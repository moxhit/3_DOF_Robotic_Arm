# Wireless Servo Control Using NRF24L01, MPU6050, and Flex Sensors

This project demonstrates how to use the NRF24L01 wireless module to send data from an MPU6050 accelerometer and two flex sensors to control three servo motors. The minimum reading of each flex sensor positions its respective servo motor at 0 degrees, and the maximum reading positions it at 180 degrees. The MPU6050's X-axis reading controls the third servo in a similar manner.

## Components Used
- 2 x NRF24L01 Wireless Modules
- 1 x MPU6050 Accelerometer
- 2 x Flex Sensors
- 3 x Servo Motors
- 1 x Arduino Nano (Transmitter)
- 1 x Arduino Uno (Receiver)
- Jumper Wires
- Breadboards

## Hardware Setup

### Transmitter (Arduino Nano)
1. **Connections:**
   - **NRF24L01:**
     - CE to D9
     - CSN to D8
     - MOSI to D11
     - MISO to D12
     - SCK to D13
     - VCC to 3.3V
     - GND to GND
   - **MPU6050:**
     - VCC to 5V
     - GND to GND
     - SDA to A4
     - SCL to A5
   - **Flex Sensors:**
     - One end to 5V (via a voltage divider if necessary)
     - Other end to A0 (Flex Sensor 1)
     - Other end to A1 (Flex Sensor 2)

### Receiver (Arduino Uno)
1. **Connections:**
   - **NRF24L01:**
     - CE to D9
     - CSN to D8
     - MOSI to D11
     - MISO to D12
     - SCK to D13
     - VCC to 3.3V
     - GND to GND
   - **Servo Motors:**
     - Signal pins to D7, D6, and D5
     - Power to 5V
     - GND to GND

## Software Setup
1. **Libraries:**
   - [RF24](https://github.com/nRF24/RF24)
   - [MPU6050](https://github.com/jrowberg/i2cdevlib/tree/master/Arduino/MPU6050)
   - [Servo](https://www.arduino.cc/en/Reference/Servo)

2. **Transmitter Code:**
   - Upload the `Transmitter.ino` file to the Arduino Nano.

3. **Receiver Code:**
   - Upload the `Receiver.ino` file to the Arduino Uno.

## Usage
1. Power up both the transmitter and receiver units.
2. The transmitter will read data from the MPU6050 and flex sensors.
3. The data will be sent wirelessly via the NRF24L01 modules.
4. The receiver will receive the data and control the servos accordingly.

## Notes
- Ensure the NRF24L01 modules are connected properly and have sufficient power.
- Adjust the delay in the code if the servos are not moving smoothly.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
