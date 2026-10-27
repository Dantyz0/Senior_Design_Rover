"""Publish a test NavSatFix on /drone_gps from an ENU offset (meters).

Example — duck 8 m east of home, 0 m north:
  ros2 run mission_control fake_gps --ros-args -p east_m:=8.0 -p north_m:=0.0
"""

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix, NavSatStatus
from std_msgs.msg import Header

from mission_control.geo import enu_to_wgs84


class FakeGps(Node):
    def __init__(self):
        super().__init__('fake_gps')
        self.declare_parameter('home_lat', 38.793000)
        self.declare_parameter('home_lon', -97.583000)
        self.declare_parameter('east_m', 8.0)
        self.declare_parameter('north_m', 0.0)
        self.declare_parameter('repeat_hz', 0.0)

        self.home_lat = float(self.get_parameter('home_lat').value)
        self.home_lon = float(self.get_parameter('home_lon').value)
        east_m = float(self.get_parameter('east_m').value)
        north_m = float(self.get_parameter('north_m').value)
        repeat_hz = float(self.get_parameter('repeat_hz').value)

        self.lat, self.lon = enu_to_wgs84(
            east_m, north_m, self.home_lat, self.home_lon
        )

        self.pub = self.create_publisher(NavSatFix, '/drone_gps', 10)
        self.get_logger().info(
            f'Test duck GPS  E={east_m:.2f} m  N={north_m:.2f} m  ->  '
            f'lat={self.lat:.8f}  lon={self.lon:.8f}'
        )

        if repeat_hz > 0.0:
            self.create_timer(1.0 / repeat_hz, self.publish_fix)
        else:
            self.create_timer(0.3, self._publish_once)
            self._sent = False

    def _publish_once(self):
        if self._sent:
            return
        self.publish_fix()
        self._sent = True
        self.get_logger().info('Published one /drone_gps fix. Ctrl-C to exit.')

    def publish_fix(self):
        msg = NavSatFix()
        msg.header = Header()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'wgs84'
        msg.status.status = NavSatStatus.STATUS_FIX
        msg.status.service = NavSatStatus.SERVICE_GPS
        msg.latitude = self.lat
        msg.longitude = self.lon
        msg.altitude = 0.0
        msg.position_covariance_type = NavSatFix.COVARIANCE_TYPE_UNKNOWN
        self.pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = FakeGps()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
