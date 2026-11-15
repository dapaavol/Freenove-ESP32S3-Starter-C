#include <Arduino.h>

//define pin reading photoresistor, then the pin driving led (based on adc readings) and PWM parameters 
#define PIN_ANALOG_IN 1
#define PIN_LED   14
#define CHN       0
#define FRQ       1000
#define PWM_BIT   12
#define LIGHT_MIN 372
#define LIGHT_MAX 2048

void setup() {
  //setup and attach PWM to pin
  ledcSetup(CHN, FRQ, PWM_BIT);
  ledcAttachPin(PIN_LED, CHN);  
}

void loop() {
  // measure ADC value at pin
  int adcValue = analogRead (PIN_ANALOG_IN);
  // map ADC value to PWM, constraining the adcValue to eliminate extreme lows or highs before mapping
  int pwmVal = map(constrain(adcValue, LIGHT_MIN, LIGHT_MAX), LIGHT_MIN, LIGHT_MAX, 0,
4095);
  //adjust led by PWM
  ledcWrite (CHN, pwmVal);
  delay(10);
}