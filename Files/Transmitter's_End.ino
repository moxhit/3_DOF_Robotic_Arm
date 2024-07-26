#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <MPU6050.h>

RF24 radio(9, 8); // CE, CSN
const uint64_t pipe = 0XE8E8F0F0E1LL;
const int flexPin1 = A0; // Analog pin connected to the first flex sensor
const int flexPin2 = A1; // Analog pin connected to the second flex sensor
MPU6050 mpu;

struct DataPacket {
  int flexvalue1;
  int flexvalue2;
  int16_t ax, ay, az;
};

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
  radio.begin();
  radio.openWritingPipe(pipe);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();
}

void loop() {
  DataPacket data;
  data.flexvalue1 = analogRead(flexPin1); // Read the analog value from the first flex sensor
  data.flexvalue2 = analogRead(flexPin2); // Read the analog value from the second flex sensor

  mpu.getAcceleration(&data.ax, &data.ay, &data.az); // Get acceleration values from MPU6050

  radio.write(&data, sizeof(data)); // Send all data via radio
  Serial.print("Flex1: ");
  Serial.print(data.flexvalue1);
  Serial.print(" Flex2: ");
  Serial.print(data.flexvalue2);
  Serial.print(" Acceleration X: ");
  Serial.println(data.ax);

  delay(100); // Adjust delay as needed to control the data transmission rate
}
