#include <Arduino.h>

//#define pinEnable 13 // Activation du driver/pilote
#define XpinStep    2 // Signal de PAS (avancement)
#define XpinDir     5 // Direction 
#define YpinStep    3 // Signal de PAS (avancement)
#define YpinDir     6 // Direction 

volatile int interrupt = 0; 

int y=0;
int x=0;
int step_x = 0;
int step_y = 0;
int pause_x = 0;
int pause_y = 0;

void setup(){
  Serial.begin(9600);
  Serial.println("Test A4988");
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
  TCCR2B = 0b00000010; // clock/256 soit 16 microsecodes
  TIMSK2 = 0b00000010;
  OCR2A = 4; // 16usec * 31 = 0,469msec (je fais un toggle de la patte step, ce qui fait une frequence de la moitiÃ©, donc une periode doubl de environ 1msec
  sei();
}

ISR(TIMER2_COMPA_vect) {
  int X_step_number = 9600;
  int Y_step_number = 12800;
  int X_frequency = 2;
  int Y_frequency = 1;

  if (step_x<X_step_number) {
    if (x==X_frequency){
      x = 0;
      digitalWrite( XpinStep, HIGH );
      digitalWrite( XpinStep, LOW );
      step_x++;
    }
  }
  else {
    pause_x++;
    if (pause_x == 60){// 3sec = 3000000usec/50usec => 60000
      pause_x = 0;
      step_x = 0;
      x = 0;
    }
  }

  if (step_y<Y_step_number) {
    if (y==Y_frequency){
      y = 0;
      digitalWrite( YpinStep, HIGH );
      digitalWrite( YpinStep, LOW );
      step_y++;
    }
  }
  else {
    pause_y++;
    if (pause_y == 60){ // 3sec = 3000000usec/50usec => 60000
      pause_y = 0;
      step_y = 0;
    }
  }

  x++;
  y++;

  delayMicroseconds(50);
}

void loop(){
}