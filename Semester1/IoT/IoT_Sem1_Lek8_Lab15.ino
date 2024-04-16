#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
  pinMode(A0, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A0);
  value = map(value, 0, 1023, 0, 255);
  analogWrite(11, value);
  value = map(value, 0, 255, 0, 100);
  lcd.setCursor(0, 1);
  int pro = value;
  String LCD = String(pro);
  lcd.print(LCD); 
  //Serial.println(LCD);
}
