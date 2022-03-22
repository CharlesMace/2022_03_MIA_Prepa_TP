#include <Arduino.h>

int count = 0;
int pin = 11;
int val;
int old_val;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin,INPUT);
  Serial.begin(9600);
  val = digitalRead(pin); // to init val
}

void loop() {
  // your need a big switch, otherwise small ones won't show the bouncing
  old_val = val;
  val = digitalRead(pin);
  if (val != old_val) {
    if (val == LOW) {
      count++;
      Serial.println("TRIGGERED!!!");
      Serial.println(count);
    }
  }
}