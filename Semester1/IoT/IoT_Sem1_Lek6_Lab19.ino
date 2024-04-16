/*
 Controlling the Position of a Servo
*/

#include <Servo.h>

Servo myservo; // create servo object to control a servo
int angle = 0; // variable to store the servo position

void setup()
{
  myservo.attach(9); // attaches the servo on pin ? to the servo object
  Serial.begin(9600);       // for debugging via the Serial Monitor
}
void loop()
{
  int pot = analogRead(A0);
  pot = map(pot, 0, 1023, 0, 180);
  myservo.write(pot);
}
