#include <Arduino.h>

#define XpinStep    2 // X step pin
#define XpinDir     5 // X direction pin 
#define YpinStep    3 // Y step pin
#define YpinDir     6 // Y direction pin

void setup(){
  pinMode(XpinDir, OUTPUT);
  pinMode(XpinStep, OUTPUT);
  pinMode(YpinDir, OUTPUT);
  pinMode(YpinStep, OUTPUT); 

  digitalWrite(XpinDir,HIGH);
  digitalWrite(YpinDir,LOW);
}

void loop() {
  for(byte i=0; i<200; i++) {
    digitalWrite(XpinStep,HIGH);
    digitalWrite(XpinStep,LOW);
  }
  for(byte y=0; y<100; y++) {
    digitalWrite(YpinStep,HIGH);
    digitalWrite(YpinStep,LOW);
  }
  delay(1);
}