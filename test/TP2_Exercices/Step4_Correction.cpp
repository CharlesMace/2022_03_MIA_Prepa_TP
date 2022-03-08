int state = 0;
int old_state = 0;
int pin = 6;
int val = 0;
unsigned long t_state = 0;
unsigned long t_0_state = 0;
unsigned long bounce_delay = 5;

int led = 13;
int state_LED = 0;
int old_state_LED = 0;
int blinkCount = 0;
int blinkNumber = 10; // blink 10 times
unsigned long t_state_LED = 0;
unsigned long t_0_state_LED = 0;
unsigned long bounce_delay_LED = 500; // blink frequency in ms

void State_Machine_LED(){
  old_state_LED = state_LED;
  switch(state_LED)  {
    case 0: // reset
      blinkCount = 0;
      state_LED = 1;
      break;
    case 1: // wait
      break;
    case 2: // turn on
      digitalWrite(led,HIGH);
      t_0_state_LED = millis();
      state_LED = 3;
      break;
    case 3: // on check time
      t_state_LED = millis();
      if (t_state_LED - t_0_state_LED > bounce_delay_LED) {
        state_LED = 4;
      }
      break;
    case 4: // Turn Off
      digitalWrite(led,LOW);
      t_0_state_LED = millis();
      state_LED = 5;
      blinkCount++;
      break;
    case 5: // Off
      t_state_LED = millis();
      if (t_state_LED - t_0_state_LED > bounce_delay_LED) {
        state_LED = 2;
      }
      // this second if is prioritary because it is after
      if (blinkCount >= blinkNumber) {
        state_LED = 0;
      }
      break;
    
  }
}
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
      state = 0;
      break;

    case 5:
      val = digitalRead(pin);
      if (val == HIGH) {
        state = 4;
      }
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(pin,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  State_Machine();
  State_Machine_LED();

  if (state == 4){
    state_LED = 2;
  }
  if (state == 4) {
    Serial.println("TRIGGERED!!!");
  }
  if (state != old_state) {
    Serial.print("state = ");
    Serial.println(state);
  }
    if (state_LED != old_state_LED) {
    Serial.print("state led = ");
    Serial.println(state_LED);
  }
}
