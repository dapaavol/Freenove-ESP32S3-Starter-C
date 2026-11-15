#include <Arduino.h>

#define PIN_ANALOG_IN 1

void setup() {
Serial.begin(115200);
}

void loop() {
int adcValue = analogRead(PIN_ANALOG_IN); //read ADC pin
double voltage = (float)adcValue / 4095.0 * 3.3; // calculate voltage at junction (across thermistor)
double Rt = 10 * voltage / (3.3 - voltage); //calculate resistance value of thermistor using voltage divider formula
double tempK = 1 / (1/(273.15 + 25) + log(Rt / 10)/3950.0);//calculate temperature (Kelvin)
double tempC = tempK - 273.15; //calculate temperature (Celsius)
double tempF = (tempC * 1.8) + 32; //calculate temperature (Fahrenheit)
Serial.printf("ADC value : %d,\tVoltage : %.2fV, \tTemperature : %.2fC\t Temperature (F) : %.2fF\n", adcValue,
voltage, tempC, tempF);
delay(1000);
}