#include <Arduino.h>

//initialize ledPins and chns byte arrays
const byte ledPins[] = {38, 39, 40};
const byte chns[] = {0, 1 , 2};
int red, green, blue;

//prototype setColor
void setColor(byte r, byte g, byte b);

//iterate through chns and ledPins, setting up for PWM
void setup() {
  for (int i = 0; i < 3; i++) {
    ledcSetup(chns[i], 1000, 8);
    ledcAttachPin(ledPins[i], chns[i]);
  }
}

//select random duty values for RGB led, then call setColor and wait
void loop() {
  red = random(0, 256);
  green = random(0, 256);
  blue = random(0, 256);
  setColor(red, green, blue);
  delay(200);
}

//assign duty values to pin array, subtracting from 255 as hardware is common anode
void setColor(byte r, byte g, byte b) {
  ledcWrite(chns[0], 255 -r);
  ledcWrite(chns[1], 255 -g);
  ledcWrite(chns[2], 255 -b);
}