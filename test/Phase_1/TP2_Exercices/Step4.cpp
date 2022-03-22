#include <Arduino.h>

int state = 0;
int state_LED = 0;
int old_state = 0;
int old_state_LED = 0;
int pin = 6;
int val = 0;
int val2 = 0;
int led1 = 13;
int led2 = 11;
int blinkCount = 0;
int blinkNumber = 12;
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
        state = 5;
      }
      break;
      
    case 4: // TRIGGERED
      Serial.println("TRIGGERED !!!");
      state = 0;
      break;

    case 5:
      val = digitalRead(pin);
      if (val == HIGH) {
        state = 4;
      }
  }
}

void State_Machine_LED() {
  old_state_LED = state_LED;
  switch (state_LED) {
  case 0:
    state_LED = 1;
    break;

  case 1:
    break;

  case 2: //Turn on
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    state_LED = 3;
    break;
  
  case 3: //
    delay(1000);
    state_LED = 4;
    break;
  
  case 4: //Turn off
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    state_LED = 5;
    blinkCount++;
    Serial.println(blinkCount);
    break;
  
  case 5: //
    if (blinkCount != blinkNumber)  {
      delay(1000);
      state_LED = 2;
    }
    else  {
      delay(1000);
      state_LED = 0;
      blinkCount = 0;
    }
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
  State_Machine_LED();

  if (state == 4) {
    state_LED = 2;
  }

  if (state == 4) {
    Serial.println("TRIGGERED!!!");
  }
  if (state != old_state) {
    Serial.print("state = ");
    Serial.println(state);
  }
}