#include <esp_now.h>
#include <WiFi.h>
#include <esp_wifi.h>

uint8_t roarmMacAddress[] = {0x30, 0x76, 0xF5, 0x7D, 0xD3, 0xD8};

// REMOVED __attribute__((packed)) to perfectly match the Robot's memory padding!
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

void onSend(const uint8_t *mac_addr, esp_now_send_status_t status) {}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  // Force radio to Channel 1 to match the Robot's Hotspot
  esp_wifi_set_promiscuous(true);
  esp_wifi_set_channel(1, WIFI_SECOND_CHAN_NONE);
  esp_wifi_set_promiscuous(false);

  if (esp_now_init() != ESP_OK) return;
  esp_now_register_send_cb(onSend);

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, roarmMacAddress, 6);
  peerInfo.channel = 1;
  peerInfo.encrypt = false;
  esp_now_add_peer(&peerInfo);
}

void loop() {
  if (Serial.available()) {
    String line = Serial.readStringUntil('\n');
    line.trim();
    if (line.length() == 0) return;

    memset(&msg, 0, sizeof(msg));

    msg.magic = 0xA5A5A5A5;
    msg.devCode = 1;
    msg.cmd = 1;

    String payload = line + "\n";
    strncpy(msg.message, payload.c_str(), sizeof(msg.message) - 1);

    esp_now_send(roarmMacAddress, (uint8_t *)&msg, sizeof(msg));

    // Echo back to the computer so we know it didn't get blocked by WSL
    Serial.println("ESP-NOW Bridged: " + payload);
  }
}
