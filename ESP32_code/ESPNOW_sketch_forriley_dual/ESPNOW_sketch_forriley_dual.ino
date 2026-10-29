/*
 * Dual-device bridge (arm + rover + ping/ACK stats).
 * Arm-only sketch is the sibling folder ESPNOW_sketch_forriley.
 *
 * USB Magic Bridge.
 *
 * This board is the middleman. Laptop talks USB. Bridge yells ESP-NOW at robots.
 *
 * Channel 1, because that's what the arm hotspot already hijacked.
 */

#include <esp_now.h>
#include <WiFi.h>
#include <esp_wifi.h>

// --- who we're bothering ---

// The arm. This MAC actually exists. Shocking.
uint8_t roarmMacAddress[] = {0x30, 0x76, 0xF5, 0x7D, 0xD3, 0xD8};

// The rover (wheels + dump solenoid). Still a glittery fake MAC until you
// paste the real one. Print WiFi.macAddress() on the rover.
uint8_t roverMacAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

// --- the packet the robots already agreed on ---
// Do NOT slap packed on this. You will "optimize" it straight into padding hell
// and then wonder why the arm pretends you don't exist.
//
// magic     : secret handshake so random RF junk doesn't count as a command
// devCode   : 1 = arm, 2 = rover. That's the whole addressing scheme. Fancy.
// joints    : arm leftovers. Rover can ignore them like unread emails.
// cmd       : 1 means "do the thing"
// message   : the actual JSON from the laptop, stuffed in a 210-char suitcase
typedef struct struct_message {
  uint32_t magic;
  byte devCode;
  float base;
  float shoulder;
  float elbow;
  float hand;
  byte cmd;
  char message[210];
} struct_message;

struct_message msg;

// --- "connection speed" theater ---
// ESP-NOW is about 1 Mbps. What you get is ACK time:
// how long until the other ESP says "yeah I got it." That's the useful number.
volatile unsigned long sendStartMs = 0;
volatile uint32_t ackOk = 0;
volatile uint32_t ackFail = 0;
volatile uint32_t rttSumMs = 0;

// Wi-Fi stack calls this after each send. Keep it short-ish.
void onSend(const uint8_t *mac_addr, esp_now_send_status_t status) {
  unsigned long rtt = millis() - sendStartMs;
  bool ok = (status == ESP_NOW_SEND_SUCCESS);
  if (ok) {
    ackOk++;
    rttSumMs += rtt;
  } else {
    ackFail++;
  }

  uint32_t total = ackOk + ackFail;
  uint32_t avg = (ackOk > 0) ? (rttSumMs / ackOk) : 0;

  Serial.print("ESP-NOW ");
  Serial.print(ok ? "ACK OK" : "ACK FAIL");
  Serial.print("  rtt=");
  Serial.print(rtt);
  Serial.print(" ms  avg=");
  Serial.print(avg);
  Serial.print(" ms  ok=");
  Serial.print(ackOk);
  Serial.print(" fail=");
  Serial.print(ackFail);
  if (total > 0) {
    Serial.print("  ");
    Serial.print((ackOk * 100) / total);
    Serial.print("%");
  }
  Serial.print("  phy~1Mbps  mac=");
  for (int i = 0; i < 6; i++) {
    if (mac_addr[i] < 16) Serial.print('0');
    Serial.print(mac_addr[i], HEX);
    if (i < 5) Serial.print(':');
  }
  Serial.println();
}

// Put a MAC on the guest list so ESP-NOW will actually talk to it.
bool addPeer(const uint8_t *mac) {
  if (esp_now_is_peer_exist(mac)) return true;
  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, mac, 6);
  peerInfo.channel = 1;
  peerInfo.encrypt = false;
  return esp_now_add_peer(&peerInfo) == ESP_OK;
}

// Figure out who this line is for. No "dev"? Congratulations, it's the arm.
// JSON "dev":2 or a "2:" prefix = rover. Anything else = arm. I am not clever.
uint8_t parseDevCode(const String &line) {
  if (line.startsWith("2:") || line.startsWith("2 ")) return 2;

  int idx = line.indexOf("\"dev\"");
  if (idx < 0) idx = line.indexOf("devCode");
  if (idx < 0) return 1;

  int colon = line.indexOf(':', idx);
  if (colon < 0) return 1;
  int value = line.substring(colon + 1).toInt();
  return (value == 2) ? 2 : 1;
}

// Stuff the struct, start the stopwatch, yeet it at the right MAC.
void sendPacket(uint8_t dev, const String &line) {
  memset(&msg, 0, sizeof(msg));
  msg.magic = 0xA5A5A5A5;
  msg.devCode = dev;
  msg.cmd = 1;

  String payload = line + "\n";
  strncpy(msg.message, payload.c_str(), sizeof(msg.message) - 1);

  const uint8_t *dest = (dev == 2) ? roverMacAddress : roarmMacAddress;
  sendStartMs = millis();
  esp_err_t err = esp_now_send(dest, (uint8_t *)&msg, sizeof(msg));
  if (err != ESP_OK) {
    Serial.print("esp_now_send error ");
    Serial.println(err);
  }
}

// Boot: USB, radio, ESP-NOW, add both robots even if one is still imaginary.
void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  // The cursed little dance that actually locks us on channel 1.
  esp_wifi_set_promiscuous(true);
  esp_wifi_set_channel(1, WIFI_SECOND_CHAN_NONE);
  esp_wifi_set_promiscuous(false);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed");
    return;
  }
  esp_now_register_send_cb(onSend);

  if (!addPeer(roarmMacAddress)) {
    Serial.println("Failed to add ARM peer");
  }
  if (!addPeer(roverMacAddress)) {
    Serial.println("Failed to add ROVER peer — set roverMacAddress to the rover ESP32 MAC");
  }

  Serial.println("ESP-NOW bridge ready. Arm=dev 1, Rover/solenoid=dev 2, channel 1");
  Serial.println("Link stats: ACK rtt (ms). Type ping  (or ping 2) to test without moving the arm.");
  Serial.println("ESP-NOW radio is ~1 Mbps; rtt is the useful speed/health number.");
}

// Sit here forever: read a line from the laptop, send it.
void loop() {
  if (!Serial.available()) return;

  String line = Serial.readStringUntil('\n');
  line.trim();
  if (line.length() == 0) return;

  // ping = "is the radio even on" without waving the arm around. Use it.
  if (line.equalsIgnoreCase("ping") || line.equalsIgnoreCase("ping 1")) {
    sendPacket(1, "{\"T\":0,\"ping\":1}");
    Serial.println("ESP-NOW ping -> arm");
    return;
  }
  if (line.equalsIgnoreCase("ping 2")) {
    sendPacket(2, "{\"dev\":2,\"ping\":1}");
    Serial.println("ESP-NOW ping -> rover");
    return;
  }

  uint8_t dev = parseDevCode(line);
  // Peel off "2:" so the rover doesn't have to parse your little prefix hobby.
  if (line.startsWith("2:") || line.startsWith("2 ")) {
    line = line.substring(2);
    line.trim();
  }

  sendPacket(dev, line);

  Serial.print("ESP-NOW Bridged [dev ");
  Serial.print(dev);
  Serial.print("]: ");
  Serial.println(line);
}
