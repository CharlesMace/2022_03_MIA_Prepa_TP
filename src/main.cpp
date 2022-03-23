#include <Arduino.h>

char SensorSimulation;

void setup() {
  Serial.begin(9600);
}

void loop() {
  //
  if (Serial.available()) {
    SensorSimulation = Serial.read();
    /*
     * Please, select the 'no new line' option on the Serial Monitor
     * in the bottom right box
     */
      Serial.print("The character received is: ");
      Serial.print(SensorSimulation);
      Serial.println();
  }
  delay(500); 
}
