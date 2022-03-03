#include <Arduino.h>

int state = 0;
int old_state = 0;
int pin = 11;
int val = 0;
unsigned long t_state = 0;
unsigned long t_0_state = 0;
unsigned long bounce_delay = 5;

void State_Machine(){
  old_state = state;
  
  switch (state){
    case 0: //reset
      state = 1;
      break;

    case 1: // START
      val = digitalRead(pin);
      if (val == LOW) {
        state = 2;  
      }
      break;

    case 2: //GO
      t_0_state = millis();
      state = 3;
      break;
      
    case 3: //WAIT
      val = digitalRead(pin);
      t_state = millis();

      if (val == HIGH) {
        state = 0;
      }
      if (t_state - t_0_state > bounce_delay) {
        state = 4;
      }
      break;
      
    case 4: // TRIGGERED
      state = 0;
      break;
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(pin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  State_Machine();
  if (state == 4) {
    Serial.println("TRIGGERED!!!");
  }

  if (state != old_state) {
    Serial.print("state = ");
    Serial.println(state);
  }
}