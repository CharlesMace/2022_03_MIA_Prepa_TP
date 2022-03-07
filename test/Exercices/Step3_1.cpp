#include <Arduino.h>

//#define pinEnable 13 // Activation du driver/pilote
#define XpinStep    2 // Signal de PAS (avancement)
#define XpinDir     5 // Direction 
#define YpinStep    3 // Signal de PAS (avancement)
#define YpinDir     6 // Direction 

void setup(){
  //pinMode( pinEnable, OUTPUT );
  pinMode( XpinDir   , OUTPUT );
  pinMode( XpinStep  , OUTPUT );
  pinMode( YpinDir   , OUTPUT );
  pinMode( YpinStep  , OUTPUT );

  digitalWrite( XpinDir   , HIGH); // Direction avant
  digitalWrite( XpinStep  , LOW);  // Initialisation de la broche step
  digitalWrite( YpinDir   , HIGH); // Direction avant
  digitalWrite( YpinStep  , LOW);  // Initialisation de la broche step

  cli();
  TCCR2A = 0b00000010;
  TCCR2B = 0b00000110; // clock/256 soit 16 microsecodes
  TIMSK2 = 0b00000010;
  OCR2A = 32; // 16usec * 31 = 0,469msec (je fais un toggle de la patte step, ce qui fait une frequence de la moitiÃ©, donc une periode doubl de environ 1msec
  sei();
}

ISR(TIMER2_COMPA_vect) {
  digitalWrite(YpinStep,!digitalRead(YpinStep));
  digitalWrite(XpinStep,!digitalRead(XpinStep));
}

void loop(){
}