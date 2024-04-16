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
}

void loop() {
  if (digitalRead(buttonApin) == LOW) {
    blinking = 1;
  }
  if (digitalRead(buttonBpin) == LOW) {
    blinking = 0;
  }
  if(blinking){
        digitalWrite(ledPin, HIGH);
        delay(100);
        digitalWrite(ledPin, LOW);
        delay(100);

  }
}
