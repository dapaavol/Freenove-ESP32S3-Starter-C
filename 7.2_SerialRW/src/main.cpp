#include <Arduino.h>

// holds incoming data
String inputString = "";
// whether the string is complete
bool stringComplete = false;

void setup() {
  delay(5000);
  Serial.begin(115200);
  Serial.println(String("\nESP32S3 initialization completed!\r\n")
                + String("Please tell me your name adventurer,\r\n")
                + String("Type then hit enter, don't worry if nothing shows up before you hit enter!. \r\n"));
}

void loop() {
  // judge whether data has been received
  if (Serial.available()) {
    // read one character
    char inChar = Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
  if (stringComplete) {
    // %s expects a C-style string (char pointer), not an Arduino String object.
    // .c_str() returns a pointer to the String's character data in the format %s expects.
    Serial.printf("inputString: %s\r\n", inputString.c_str());
    inputString = "";
    stringComplete = false;
  }
}