// lab09.ino
int lightPin = A0;
void setup() {
 pinMode(lightPin, INPUT);
 pinMode(LED_BUILTIN, OUTPUT);
 // open the serial port at 9600 bps:
 Serial.begin(9600);
}
void loop()
{
 int ldrValue = analogRead(A0);
 Serial.println(ldrValue);
 
 if (ldrValue > 500) {
 digitalWrite(LED_BUILTIN, HIGH);
 }
  else {
  digitalWrite(LED_BUILTIN, LOW);
 }
 delay (100);
}