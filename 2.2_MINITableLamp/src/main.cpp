#include <Arduino.h>

void reverseGPIO(int pin);   // Function prototype

#define PIN_LED    2
#define PIN_BUTTON 13
// reverse io in setup damage board
void setup() {
  // initialize digital pin PIN_LED as an output and PIN_BUTTON as an input.
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
}

// button push in, debounce read led pin and write reverse to it only once per button push
void loop() {
  if (digitalRead(PIN_BUTTON) == LOW) {
    delay(20);
    if (digitalRead(PIN_BUTTON) == LOW) {
      reverseGPIO(PIN_LED);
  }
while (digitalRead(PIN_BUTTON) == LOW);
delay(20);
while (digitalRead(PIN_BUTTON) == LOW);
}
}
void reverseGPIO(int pin) {
digitalWrite(pin, !digitalRead(pin));
}