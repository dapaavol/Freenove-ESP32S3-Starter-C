#include <Arduino.h>

// define (text substituion not variable in memory) led pin and pwm channel, f, resolution/precision:
#define PIN_LED   21
#define CHN       0
#define FRQ       1000
#define PWM_BIT   8

void setup() {
  //setup and attach pin to pwm channel
  ledcSetup(CHN, FRQ, PWM_BIT);
  ledcAttachPin(PIN_LED, CHN);
}

void loop() {
  // fade light in and out
  for (int i = 0; i < 255; i++) {
    ledcWrite(CHN, i);
    delay(10);
  }
  for (int i = 255; i > -1; i--) {
    ledcWrite(CHN, i);
    delay(10);
  }
}
