#include <Arduino.h>

#define PIN_LED    2
#define PIN_BUTTON 13
// reverse io in setup damage board
void setup() {
  // initialize digital pin PIN_LED as an output and PIN_BUTTON as an input.
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
}

// button pushed in, circuit to grnd completes, pin reads LOW, led on
void loop() {
  if (digitalRead(PIN_BUTTON) == LOW) {
    digitalWrite(PIN_LED,HIGH);
  }else{
    digitalWrite(PIN_LED,LOW);
  }
}