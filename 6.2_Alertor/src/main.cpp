#include <Arduino.h>

//define buzzer and button pins, PWM channel and prototype alert
#define PIN_BUZZER  14
#define PIN_BUTTON  21    
#define CHN         0

void alert();

//setup mode of pins, PWM channel using old API framework, startup tone for 0.3s
void setup () {
  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  ledcSetup(CHN, 1, 10);
  ledcAttachPin(PIN_BUZZER, CHN);
  ledcWriteTone(CHN, 2000);
  delay(300);
}

//when button pressed, call alert() else silence
void loop () {
if
  (digitalRead(PIN_BUTTON) == LOW) {
  alert();
  }
else {
  ledcWriteTone(CHN, 0);
}
}

//function to smoothly cycle from 500-1500hz tone using a sin wave to calculate
void alert () {
float sinVal;
int toneVal;
for (int x = 0; x < 360; x += 10) {
  sinVal = sin(x * (PI / 180));
  toneVal = (1000 + sinVal * 500);
  ledcWriteTone(CHN, toneVal);
  delay(10); 
}
}