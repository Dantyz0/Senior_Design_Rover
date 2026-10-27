import os
from glob import glob
from setuptools import find_packages, setup

package_name = 'roarm_driver'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.py')),
        (os.path.join('share', package_name, 'config'), glob('config/*')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Daniel',
    maintainer_email='dlmoran@ksu.edu',
    description='RoArm hardware drivers including ESP-NOW Magic Bridge',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'roarm_driver = roarm_driver.roarm_driver:main',
            'espnow_bridge = roarm_driver.espnow_bridge:main',
            'espnow_keyboard_teleop = roarm_driver.espnow_keyboard_teleop:main',
            'duck_pickup = roarm_driver.duck_pickup:main',
        ],
    },
)
