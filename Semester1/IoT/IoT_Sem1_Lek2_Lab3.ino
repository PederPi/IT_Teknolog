/***********************************************************
File name: lab01.ino
Description: use push buttons with digital inputs to turn 
             an LED on and off
***********************************************************/
int ledPin = 5;
int buttonApin = 9;
int buttonBpin = 8;
int blinking = 0;

byte leds = 0;

void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(2) == LOW){
    digitalWrite(ledPin, HIGH);
  }
  else if(digitalRead(3) == LOW){
    digitalWrite(ledPin, LOW);
  }
}
