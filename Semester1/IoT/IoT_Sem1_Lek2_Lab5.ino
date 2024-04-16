/***********************************************************
File name: lab01.ino
Description: use push buttons with digital inputs to turn 
             an LED on and off
***********************************************************/
int ledPin = 5;
int buttonApin = 9;
int buttonBpin = 8;
int blinking = 0;
int aChange = 0;
int bChange = 1;
int aCounter = 0;
int bCounter = 0;

byte leds = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(buttonApin) == LOW && bChange == 1) {
    blinking = 1;
    aChange = 1;
    bChange = 0;
    Serial.println("ON");
    aCounter ++;
    Serial.print("On button pressed: ");
    Serial.println(aCounter);
    Serial.print("Off button pressed: ");
    Serial.println(bCounter);
    Serial.print("Total buttons pressed: ");
    Serial.println(aCounter + bCounter);
  }
  else if(digitalRead(buttonBpin) == LOW && aChange == 1) {
    blinking = 0;
    bChange = 1;
    aChange = 0;
    Serial.println("OFF");
    bCounter ++;
    Serial.print("On button pressed: ");
    Serial.println(aCounter);
    Serial.print("Off button pressed: ");
    Serial.println(bCounter);
    Serial.print("Total buttons pressed: ");
    Serial.println(aCounter + bCounter);
  }
  if(blinking) {
        digitalWrite(ledPin, HIGH);
        delay(100);
        digitalWrite(ledPin, LOW);
        delay(100);
  }
}
