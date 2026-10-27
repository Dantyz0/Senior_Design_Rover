"""Local tangent-plane GPS math (WGS84 equirectangular / ENU).

Gazebo's default XY matches this if home GPS is the spawn origin and the
rover faces +X (east):
  x = east  (meters)
  y = north (meters)

Accurate enough for campus-scale (hundreds of meters). Swap to a full
ECEF→ENU conversion later if you add RTK and need centimeter mapping.
"""

from __future__ import annotations

import math


def _meters_per_degree(origin_lat_deg: float) -> tuple[float, float]:
    lat = math.radians(origin_lat_deg)
    m_per_deg_lat = (
        111132.92
        - 559.82 * math.cos(2.0 * lat)
        + 1.175 * math.cos(4.0 * lat)
    )
    m_per_deg_lon = (
        111412.84 * math.cos(lat)
        - 93.5 * math.cos(3.0 * lat)
    )
    return m_per_deg_lat, m_per_deg_lon


def wgs84_to_enu(
    latitude_deg: float,
    longitude_deg: float,
    origin_lat_deg: float,
    origin_lon_deg: float,
) -> tuple[float, float]:
    """Return (east_m, north_m) relative to the origin."""
    m_per_deg_lat, m_per_deg_lon = _meters_per_degree(origin_lat_deg)
    north_m = (latitude_deg - origin_lat_deg) * m_per_deg_lat
    east_m = (longitude_deg - origin_lon_deg) * m_per_deg_lon
    return east_m, north_m


def enu_to_wgs84(
    east_m: float,
    north_m: float,
    origin_lat_deg: float,
    origin_lon_deg: float,
) -> tuple[float, float]:
    """Return (latitude_deg, longitude_deg) for an ENU offset from origin."""
    m_per_deg_lat, m_per_deg_lon = _meters_per_degree(origin_lat_deg)
    latitude_deg = origin_lat_deg + north_m / m_per_deg_lat
    longitude_deg = origin_lon_deg + east_m / m_per_deg_lon
    return latitude_deg, longitude_deg
