#include <Arduino.h>

//define pin reading potientiometer, then the pin driving led (based on adc readings) and PWM parameters 
#define PIN_ANALOG_IN 1
#define PIN_LED   14
#define CHN       0
#define FRQ       1000
#define PWM_BIT   8

unsigned long lastPrintTime = 0;

void setup() {
  //begin serial monitor
  Serial.begin(115200);
  //setup and attach PWM to pin
  ledcSetup(CHN, FRQ, PWM_BIT);
  ledcAttachPin(PIN_LED, CHN);  
}

void loop() {
  // measure ADC value at pin, display value and adjust brightness of LED using PWM
  int adcValue = analogRead (PIN_ANALOG_IN);
  int pwmValue = adcValue / 16;
  ledcWrite (CHN, pwmValue);
  //print brightness as a percent of adc every 5s, iterate on lastPrintTime
  float brightnessValue = adcValue / 4095.0 * 100;
  if (millis() - lastPrintTime >= 5000)
  {
    Serial.printf("%.1f%%\n", brightnessValue);
    lastPrintTime += 5000;
  }
}