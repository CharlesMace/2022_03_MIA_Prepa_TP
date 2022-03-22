#include <Arduino.h>

#define XpinStep    2 // Signal de PAS (avancement)
#define XpinDir     5 // Direction 
#define YpinStep    3 // Signal de PAS (avancement)
#define YpinDir     6 // Direction 

unsigned int y=0;
unsigned int x=0;
unsigned int step_x = 0;
unsigned int step_y = 0;
unsigned int pause_x = 0;
unsigned int pause_y = 0;

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
  delay(10);
}

void loop(){
  int X_step_number = 9600;
  int Y_step_number = 12800;
  int X_frequency = 40;
  int Y_frequency = 25;

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
    if (pause_x == 60000){// 3sec = 3000000usec/50usec => 60000
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
    if (pause_y == 60000){ // 3sec = 3000000usec/50usec => 60000
      pause_y = 0;
      step_y = 0;
    }
  }

  x++;
  y++;

  delayMicroseconds(50);

}