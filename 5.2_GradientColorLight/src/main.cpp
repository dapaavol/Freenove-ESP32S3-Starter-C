#include <Arduino.h>

//initialize ledPins and chns byte arrays
const byte ledPins[] = {38, 39, 40};
const byte chns[] = {0, 1 , 2};


//prototype setColor, wheel
void setColor(long rgb);
long wheel(int pos);

//iterate through chns and ledPins, setting up for PWM
void setup() {
  for (int i = 0; i < 3; i++) {
    ledcSetup(chns[i], 1000, 8);
    ledcAttachPin(ledPins[i], chns[i]);
  }
}

//call setColor, iterating through all "positions" on the wheel
void loop() {
    for (int i = 0; i < 256; i++) {
        setColor(wheel(i));
        delay(20);
    }    
}

//assign duty values to chns array, "unpacking" the R,G,B values from the output of wheel using bit shifting and masking
void setColor(long rgb) {
  ledcWrite(chns[0], 255 - (rgb >> 16) & 0xFF);
  ledcWrite(chns[1], 255 - (rgb >> 8) & 0xFF);
  ledcWrite(chns[2], 255 - (rgb >> 0) & 0xFF);
}

//takes position on the wheel using the for in main loop. creates a 24 bit long by putting each R,G,B value into the correct position
long wheel(int pos) {
    long WheelPos = pos % 0xff;
    if (WheelPos < 85) {
        return ((255 - WheelPos * 3)  << 16) | ((WheelPos * 3) << 8);
    } else if (WheelPos < 170) {
        WheelPos -= 85;
        return (((255 - WheelPos * 3) << 8) | (WheelPos * 3));
    } else {
        WheelPos -= 170;
        return ((WheelPos * 3) << 16 | (255 - WheelPos * 3));
    }
}