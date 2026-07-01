#include <Arduino.h>

#define LED_BUILTIN 2

void setup() {
  // set pin 2 as an output pin
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // set parameters for high and low states of the LED
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}