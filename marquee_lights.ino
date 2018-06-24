const int pinLed[] = {23, 22, 21, 5, 4, 3};
const int potLed = 14;
const int pushLed = 12;
volatile int i;
// speed 
volatile int spd;
// brightness
int bright = 20;
volatile int dir = 1;

void setup() {
 for (i = 0; i < 6; i++) {
  pinMode(pinLed[i], OUTPUT);
 }
 pinMode(pushLed, INPUT_PULLUP);
 attachInterrupt(pushLed, dirchg, RISING);
 i = 0;
 //Serial.begin(38400);
}

void loop() {
  //loop until button is pressed, then change direction
  while (dir == 1) {
    if (i == 6) i = 0;
    spd = analogRead(potLed) / 4;
    analogWrite(pinLed[i], bright);
    delay(spd);
    analogWrite(pinLed[i + 1], 0);
    delay(spd);
    analogWrite(pinLed[i], 0);
    i++;
  }
    while (dir == 0) {
      if (i == -1) i = 5;
      spd = analogRead(potLed) / 4;
      analogWrite(pinLed[i], bright);
      delay(spd);    
      analogWrite(pinLed[i - 1], 0);
      delay(spd);     
      analogWrite(pinLed[i], 0);
      i--;
  }
}
/*
int marqueeLed (int pinStart) {
 
  

}
*/
void dirchg() {
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > 200) {
    dir = !dir;
  }
  last_interrupt_time = interrupt_time;
}
