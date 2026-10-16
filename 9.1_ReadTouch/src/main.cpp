#include <Arduino.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  // read touch sensor at pin 14 display formatted output:
  Serial.printf("Touch Value: %d \r\n", touchRead(T14));
  delay(5000);
}
