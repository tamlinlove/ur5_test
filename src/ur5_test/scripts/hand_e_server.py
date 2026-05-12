#!/usr/bin/env python3
import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from control_msgs.action import GripperCommand
import serial
import time

class HandESerialActionServer(Node):
    def __init__(self):
        super().__init__('hand_e_action_server')
        
        # Serial Setup
        self.port = '/tmp/ttyUR'
        try:
            self.ser = serial.Serial(self.port, 115200, timeout=1)
            self.get_logger().info(f"Connected to {self.port}")
            self.initialize_gripper()
        except Exception as e:
            self.get_logger().error(f"Failed to open serial port: {e}")

        self._action_server = ActionServer(
            self,
            GripperCommand,
            '/gripper_action_controller/gripper_cmd',
            execute_callback=self.execute_callback)

    def calculate_crc(self, data):
        """Calculates the CRC16 for Modbus RTU."""
        crc = 0xFFFF
        for pos in data:
            crc ^= pos
            for _ in range(8):
                if (crc & 1) != 0:
                    crc >>= 1
                    crc ^= 0xA001
                else:
                    crc >>= 1
        return crc.to_bytes(2, byteorder='little')

    def send_hex(self, hex_bytes):
        self.ser.write(hex_bytes)
        time.sleep(0.1)
        return self.ser.read(self.ser.in_waiting)

    def initialize_gripper(self):
        self.get_logger().info("Resetting and Activating Gripper...")
        # Reset: 09 10 03 E8 00 03 06 00 00 00 00 00 00 73 30
        self.send_hex(b'\x09\x10\x03\xE8\x00\x03\x06\x00\x00\x00\x00\x00\x00\x73\x30')
        time.sleep(0.5)
        # Activate: 09 10 03 E8 00 03 06 01 00 00 00 00 00 72 E1
        self.send_hex(b'\x09\x10\x03\xE8\x00\x03\x06\x01\x00\x00\x00\x00\x00\x72\xE1')
        time.sleep(4.0)
        self.get_logger().info("Gripper Ready.")

    async def execute_callback(self, goal_handle):
        pos_request = goal_handle.request.command.position
        effort_request = goal_handle.request.command.max_effort
        
        self.get_logger().info(f'Goal - Pos: {pos_request}, Effort: {effort_request}')

        # 1. Map Position (0.0 to 0.025) to (255 to 0)
        # Note: Hand-E is 0xFF (255) for fully closed, 0x00 (0) for fully open
        pos_byte = int(max(0, min(255, (1 - (pos_request / 0.025)) * 255)))

        # 2. Map Effort (assuming 0.0 to 100.0 range) to (0 to 255)
        # If effort is not provided (0.0), we default to max force (255)
        if effort_request <= 0.0:
            force_byte = 255 
        else:
            force_byte = int(max(0, min(255, (effort_request / 100.0) * 255)))

        # 3. Build Modbus Frame
        # Header + Data (Action, Reserved, Reserved, Position, Speed, Force)
        speed_byte = 255 # Hardcoded to max speed for this example
        payload = bytearray([0x09, 0x10, 0x03, 0xE8, 0x00, 0x03, 0x06, 0x09, 0x00, 0x00, pos_byte, speed_byte, force_byte])
        
        # 4. Append CRC
        full_command = payload + self.calculate_crc(payload)
        
        self.get_logger().info(f'Sending Command: {full_command.hex()}')
        self.send_hex(full_command)
        
        time.sleep(1.5) # Allow time for movement

        goal_handle.succeed()
        result = GripperCommand.Result()
        result.position = pos_request
        result.effort = effort_request
        result.reached_goal = True
        
        return result

def main(args=None):
    rclpy.init(args=args)
    server = HandESerialActionServer()
    rclpy.spin(server)
    rclpy.shutdown()

if __name__ == '__main__':
    main()