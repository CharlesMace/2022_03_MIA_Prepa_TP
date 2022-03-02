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
  digitalWrite(YpinDir,HIGH);
  
	// … add stepper setup and direction …
  cli();
  TCCR2A = 0b00000010; // WGM21=1 => CTC mode
  TCCR2B = 0b00000110; // CS21 and CS22=1 => prescaler 256 
  TIMSK2 = 0b00000010; // set OCIE2A compare interrupt for channel A
  OCR2A = 15; // set compare register value
  sei();
}

// the program jump to this section every interruption generation
ISR(TIMER2_COMPA_vect) { 
	digitalWrite(XpinStep,HIGH); // pulse generation
  digitalWrite(XpinStep,LOW);
  digitalWrite(YpinStep,HIGH); // pulse generation
  digitalWrite(YpinStep,LOW);
}

void loop() {
}