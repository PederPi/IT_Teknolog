// Lab02.ino
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(9, OUTPUT); // 9 port mode
  pinMode(10, OUTPUT); // 10 port mode
  pinMode(11, OUTPUT); // 11 port mode
}
// Add the main program code into the continuous loop() function
void loop()
{
  //Port 11 LED = RED
  digitalWrite(LED_BUILTIN, 1);
  digitalWrite(9, 1); // 09 port on
  digitalWrite(10, 0); // 10 port off
  digitalWrite(11, 1); // 11 port on
  delay(500); //500ms delay
  digitalWrite(LED_BUILTIN, 0);
  digitalWrite(9, 0); //09 port off
  digitalWrite(10, 1); //10 port on
  digitalWrite(11, 0); //11 port off
  delay(500);
}