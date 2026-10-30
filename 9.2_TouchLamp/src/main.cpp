#include <Arduino.h>

//preprocessor macros, not variables
#define PIN_LED 21
#define PRESS_VAL 150000 //Set a threshold to judge touch
#define RELEASE_VAL 60000 //Set a threshold to judge release

//defines function to reverse the led driving pin between high and low
void reverseGPIO(int pin) {
digitalWrite(pin, ! digitalRead(pin));
}

//variable to reduce "bounce"
bool isProcessed = false;

void setup() {
Serial.begin(115200);
pinMode(PIN_LED, OUTPUT);
}

void loop() {
if (touchRead(T14) > PRESS_VAL) {
//if not already processed, prints message and calls reverseGPIO
if (! isProcessed) {
isProcessed = true;
Serial.println("Touch detected! ");
reverseGPIO(PIN_LED);
}
}
if (touchRead(T14) < RELEASE_VAL) {
//once capacitance reading falls below release value, check if processed then resets isProcessed bool and prints message
if (isProcessed) {
isProcessed = false;
Serial.println("Released! ");
}
}
}
