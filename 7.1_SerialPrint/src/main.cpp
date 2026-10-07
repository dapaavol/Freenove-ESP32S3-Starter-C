#include <Arduino.h>

void setup() {
  // start serial port, set baud rate. Print message to confirm setup.
  Serial.begin(115200);
  Serial.println("ESP32-S3 initialization complete! ");
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.printf("Running Time: %.lf s\n", millis() / 1000.0f);
delay(1000);
}
