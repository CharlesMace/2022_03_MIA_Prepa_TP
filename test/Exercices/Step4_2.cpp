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

  TCNT2=0;
  TCCR2A = 0b00010011; // COM2B0 set, Fast PWM Phase: WGM21 and WGM20 set
  TCCR2B = 0b00001011; // prescaler 32 and WGM22 set
  delay(10);

}

void loop(){
  Serial.println("OCRA 50");
  OCR2A = 50;
  analogWrite( YpinStep, 1 );
  delay(3000);
  Serial.println("OCRA 100");
  OCR2A = 100;
  analogWrite( YpinStep, 1 );
  delay(3000);
  Serial.println("OCRA 150");
  OCR2A = 150;
  analogWrite( YpinStep, 1 );
  delay(3000);
  Serial.println("OCRA 200");
  OCR2A = 200;
  analogWrite( YpinStep, 1 );
  delay(3000);
  Serial.println("OCRA 255");
  OCR2A = 255;
  analogWrite( YpinStep, 1 );
  delay(3000);
  Serial.println("stop");
  analogWrite( YpinStep, 0 );
  delay(3000);
}
