//For Arduino UNO

#include <SoftwareSerial.h>

SoftwareSerial softSerial1(4, 5); // RX, TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  softSerial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // copy from virtual serial line to uart and vice versa
  if (Serial.available()) {
    char c = (char)Serial.read();
    softSerial1.write(c);
  }
  if (softSerial1.available()) {
    char c = (char)softSerial1.read();
    Serial.write(c);
  }
}
