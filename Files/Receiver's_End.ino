#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

RF24 radio(9, 8); // CE, CSN
const uint64_t pipe = 0XE8E8F0F0E1LL;

Servo servo1;  // Servo connected to the first flex sensor
Servo servo2;  // Servo connected to the second flex sensor
Servo servo3;  // Servo controlled by MPU6050

struct DataPacket {
  int flexvalue1;
  int flexvalue2;
  int16_t ax, ay, az;
};

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();
  
  servo1.attach(7);  // Attach servo to pin 7
  servo2.attach(6);  // Attach servo to pin 6
  servo3.attach(5);  // Attach servo to pin 5
}

void loop() {
  if (radio.available()) {
    DataPacket data;
    radio.read(&data, sizeof(data)); // Read incoming data

    int servoPosition1 = map(data.flexvalue1, 0, 1023, 0, 180); // Map flex sensor 1 value to servo position
    int servoPosition2 = map(data.flexvalue2, 0, 1023, 0, 180); // Map flex sensor 2 value to servo position
    int servoPosition3 = map(data.ax, -17000, 17000, 0, 180); // Map MPU6050 X-axis value to servo position

    servo1.write(servoPosition1); // Move first servo
    servo2.write(servoPosition2); // Move second servo
    servo3.write(servoPosition3); // Move third servo

    Serial.print("Servo1: ");
    Serial.print(servoPosition1);
    Serial.print(" Servo2: ");
    Serial.print(servoPosition2);
    Serial.print(" Servo3: ");
    Serial.println(servoPosition3);

    delay(100); // Adjust delay as needed to control the servo movement rate
  }
}
