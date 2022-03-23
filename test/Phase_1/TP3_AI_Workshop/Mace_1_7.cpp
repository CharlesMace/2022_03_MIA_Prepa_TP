#include <Arduino.h>

int incomingByte = 0; // Define varriable in order to read tht value from the keyboard
int object = 0; // define the varriable object 

void setup() {
  Serial.begin(9600); // ouvre le port série et fixe le débit à 9600 bauds
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    }
  if (incomingByte == 97) { //the number of bytes send by the 1 on the keyboard is 49
    object = 1; // If 1 is press on the keyboard sensor 1 goes to state 1 (signal)
  }
  if (incomingByte == 122) { //The number of bytes correspond to 2 on the keyboard
    object = 2; // If 2 is press, sensor 2 goes to state 1
  }
  if (incomingByte == 101) { // Number of bytes corresponding to 3 on the key board
    object = 3; // If 3 is press, sensor 3 goes to state 1
  }
  if (incomingByte == 114) { // Number of bytes corresponding to 3 on the key board
    object = 4; // If 3 is press, sensor 3 goes to state 1
  }
  Serial.print("Octet recu: ");
  Serial.println((char)incomingByte, DEC);
  Serial.println(object);
  object = 0;
delay (1000);
}
