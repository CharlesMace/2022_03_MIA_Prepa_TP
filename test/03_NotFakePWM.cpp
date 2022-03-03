#include <Arduino.h>

#define XpinStep    2 // Signal de PAS (avancement)
#define XpinDir     5 // Direction
#define YpinStep    3 // Signal de PAS (avancement)
#define YpinDir     6 // Direction

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

  // 32 prescaler freq = freq-clock/N*510 (N = prescaler) c'est du double pwm

  TCCR2A = 0;
  TCCR2B = 0;
  TCNT2=0;
  TCCR2A = 0b00100011; // COM2B1 set, Fast PWM Phase
  TCCR2B = 0b00000001; // prescaler 1
  OCR2A = 128; //duty cycle 50%
 
  delay(10);

  analogWrite( YpinStep, 0 );
}

void loop(){
  Serial.println("Prescaler 1");
  TCCR2B = 0b00000001; // prescaler 1
  analogWrite( YpinStep, 50 );
  delay(3000);
  analogWrite( YpinStep, 0 );
  Serial.println("Prescaler 8");
  TCCR2B = 0b00000010; // prescaler 8
  analogWrite( YpinStep, 50 );
  delay(3000);
  analogWrite( YpinStep, 0 );
  Serial.println("Prescaler 32");
  TCCR2B = 0b00000011; // prescaler 32
  analogWrite( YpinStep, 50 );
  delay(3000);
  analogWrite( YpinStep, 0 );
  Serial.println("Prescaler 64");
  TCCR2B = 0b00000100; // prescaler 64
  analogWrite( YpinStep, 50 );
  delay(3000);
  analogWrite( YpinStep, 0 );
  Serial.println("Prescaler 128");
  TCCR2B = 0b00000101; // prescaler 128
  analogWrite( YpinStep, 50 );
  delay(3000);
  analogWrite( YpinStep, 0 );
  Serial.println("Prescaler 256");
  TCCR2B = 0b00000110; // prescaler 256
  analogWrite( YpinStep, 50 );
  delay(3000);
  analogWrite( YpinStep, 0 );
  Serial.println("Prescaler 1024");
  TCCR2B = 0b00000111; // prescaler 1024
  analogWrite( YpinStep, 50 );
  delay(3000);
  analogWrite( YpinStep, 0 );
  delay(5000);
}