#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"
//Adafruit_TCS34725 tcs = Adafruit_TCS34725();
//Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X);

// SENSOR INPUTS // ***********************************************************
int IR_01 = A2; // Resume on CNC shield
int IR_02 = A3; // CoolEn on CNC shield 
int IR_03 = A0; // Abort on CNC shield
int IR_04 = A1; // Hold on CNC shield
// The colour sensor is connected to the SDA/SCL pins of the Arduino (A4 abd A5)
// ****************************************************************************

int CompteurSimulation = 0;
int r = 0;
int g = 0;
int b = 0;
int c = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
      if (Serial.available()) {
        Serial.println("What is the value of r?");
        r = Serial.read();
        delay(2000);
        Serial.print("The character received is: ");
        Serial.print(r);
        Serial.println();
        Serial.println("What is the value of g?");
        g = Serial.read();
        delay(2000);
        Serial.println("The character received is: ");
        Serial.print(g);
        Serial.println();
        Serial.println("What is the value of b?");
        b = Serial.read();
        delay(2000);
        Serial.println("The character received is: ");
        Serial.print(b);
        Serial.println();
        Serial.println("What is the value of c?");
        c = Serial.read();
        delay(2000);
        Serial.println("The character received is: ");
        Serial.print(c);
        Serial.println();
      }
    Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
    Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
    Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
    Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
    Serial.print("IR 01: "); Serial.print(digitalRead(IR_01)); Serial.print(" ");
    Serial.print("IR 02: "); Serial.print(digitalRead(IR_02)); Serial.print(" ");
    Serial.print("IR 03: "); Serial.print(digitalRead(IR_03)); Serial.print(" ");
    Serial.print("IR 04: "); Serial.print(digitalRead(IR_04));
    delay(500); 
}
