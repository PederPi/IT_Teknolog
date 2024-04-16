/***********************************************************
Author: Hannah Bidstrup og Jonas Peder Iversen
Rover Project, IT-Teknolog
***********************************************************/
//Joystick pins:
//A1: Y-Axis
//A0: X-Axis
int joyStickSwitch = 6;
int xDirection = 0;
int yDirection = 0;

//Motor speed pins:
int rightMotorPWN = 7;              //Right Motor = Motor 1 = Motor A
int leftMotorPWN = 8;               //Left Motor = Motor 2 = Motor B

//Motor direction pins:
int rightMotorDirection1 = 2;
int rightMotorDirection2 = 3;
int leftMotorDirection1 = 4;
int leftMotorDirection2 = 5;

//Variable used by multiple functions for controlling motor frequency and speed:
int ICR4Variable = 0;

//Motor frequency:
int PWMFrequency = 25000;

void setup(){
  
  Serial.begin(9600);

  //Initialize pins as output:
  //PWM motor pins:
  pinMode(rightMotorPWN, OUTPUT);
  pinMode(leftMotorPWN, OUTPUT);
  //Motor direction pins:
  pinMode(rightMotorDirection1, OUTPUT);
  pinMode(rightMotorDirection2, OUTPUT);
  pinMode(leftMotorDirection1, OUTPUT);
  pinMode(leftMotorDirection2, OUTPUT);

  //Change pin 7 and 8 to PWM pins:
  analogWrite(rightMotorPWN, 128);
  analogWrite(leftMotorPWN, 128);

  //Set hardware PWM frequency:
  setFrequency(PWMFrequency);

  //Joystick pin setup:
  pinMode(joyStickSwitch, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop(){
  getJoyStickInput();
  updateMotors();
  delay(100);
}

void getJoyStickInput(){
  xDirection = map(analogRead(A0), 0, 1023, -100, 100);
  yDirection = map(analogRead(A1), 0, 1023, -100, 100);
}

void setRightMotorDirection(int direction){
  if(direction == 1){
    digitalWrite(rightMotorDirection1, LOW);
    digitalWrite(rightMotorDirection2, HIGH);
  }else if(direction == 0){
    digitalWrite(rightMotorDirection1, HIGH);
    digitalWrite(rightMotorDirection2, LOW);
  }
}

void setLeftMotorDirection(int direction){
  if(direction == 1){
    digitalWrite(leftMotorDirection1, HIGH);
    digitalWrite(leftMotorDirection2, LOW);
  }else if(direction == 0){
    digitalWrite(leftMotorDirection1, LOW);
    digitalWrite(leftMotorDirection2, HIGH);
  }
}


void setRightMotorSpeed(int percentageDutyCycle) {
  OCR4B  = ICR4Variable * ((float)(percentageDutyCycle / 100.0));
}

void setLeftMotorSpeed(int percentageDutyCycle) {
  OCR4C  = ICR4Variable * ((float)(percentageDutyCycle / 100.0));
}


void setFrequency(int frequency){
  noInterrupts();
  TCCR4A = 0; // clear register
  TCCR4B = 0; // clear register
  TCNT4  = 0; // clear register

  ICR4   = (F_CPU / frequency) / 2;
  ICR4Variable = ICR4;

  TCCR4A = _BV(COM4C1) | _BV(COM4B1)| _BV(WGM41);       //COM4C1 = pin 8, COM4B1 = pin 7
  TCCR4B = _BV(WGM43) | _BV(CS40);
  interrupts();
}

void updateMotors(){
  if(yDirection > 0){
    if(xDirection > 0){
    setRightMotorDirection(1);
    setLeftMotorDirection(1);
    }else if(xDirection < 0){
    setRightMotorDirection(0);
    setLeftMotorDirection(0);
    }
    setRightMotorSpeed(((50 - (yDirection / 2)) / 100) * abs(xDirection));
    setLeftMotorSpeed(((50 + (yDirection / 2)) / 100) * abs(xDirection));

  }else if(yDirection < 0){
    if(xDirection > 0){
    setRightMotorDirection(1);
    setLeftMotorDirection(1);
    }else if(xDirection < 0){
    setRightMotorDirection(0);
    setLeftMotorDirection(0);
    }
    setRightMotorSpeed(((50 - (yDirection / 2)) / 100) * abs(xDirection));
    Serial.print("Right: ");
    Serial.println(((50 - (yDirection / 2)) / 100) * abs(xDirection));
    setLeftMotorSpeed(((50 + (yDirection / 2)) / 100) * abs(xDirection));
    Serial.print("Left: ");
    Serial.println(((50 + (yDirection / 2)) / 100) * abs(xDirection));
  }
}
