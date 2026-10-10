#include <Arduino.h>

//initialize variable to correct for 20s delay
uint32_t startTime = 0;

void setup() {
  // start serial port, set baud rate. Print message to confirm setup.
  delay(20000);
  Serial.begin(115200);
  startTime = millis();
  Serial.println("ESP32-S3 initialization complete- finally! ");
}

void loop() {
  // print formatted time 1/s since Serial.begin, not board restart:
Serial.printf("Running Time: %.lf s\n", (millis() - startTime) / 1000.0f);
delay(1000);
}
