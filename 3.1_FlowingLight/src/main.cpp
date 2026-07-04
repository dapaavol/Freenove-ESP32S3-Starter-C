#include <Arduino.h>

// declare byte array for led pins, initialize ledCounts variable
byte ledPins[] = {21, 1, 47, 2, 48, 42, 38, 41, 39, 40};
int ledCounts;

void setup() {
  // count entries in ledPins, then iterate through ledPins array by adding 1 to ledCounts until size of array ledPins, setting all the pins in the array into outputs
  ledCounts = sizeof(ledPins);
  for (int i = 0; i < ledCounts; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  //use for loops to turn LEDs on and off ascending the array, then the reverse direction
  for (int i = 0; i < ledCounts; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(1000);
    digitalWrite(ledPins[i], LOW);
  }
  delay(1000);
  for (int i = ledCounts - 1; i > -1; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(1000);
    digitalWrite(ledPins[i], LOW);
  }
  delay(1000);
}