#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(12,OUTPUT); // first LED
  pinMode(13,OUTPUT); // second LED 
  pinMode(11,INPUT_PULLUT); // button without resistor
  //pinMode(11,INPUT); // button with resistor 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  delay(2000);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  delay(500);
  
  Serial.println(digitalRead(11)); 
}