#include <Arduino.h>

#define PIN_ANALOG_IN 1

void setup() {
  // beging serial comm at 115200 baud:
  Serial.begin(115200);
}

void loop() {
  // measure ADC value at pin, convert to voltage and display both:
  int adcValue = analogRead (PIN_ANALOG_IN);
  double voltage = (adcValue / 4095.0 ) * 3.3;
  Serial.printf("ADC Val: %d, \t Voltage: %.2fV\n", adcValue, voltage);
  delay(5000);
}
