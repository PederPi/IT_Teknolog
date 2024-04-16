#include <dht.h>

dht DHT;
int htSensor;
/*
* Read the temperature sensor LM35
*/
int LM35_pin = A0; // LM35 output connected to analog pin ?
float LM35_temp; // temperature from LM35
void setup()
{
pinMode(LM35_pin, INPUT); // make pin as Input reading pin
Serial.begin(9600); // Open serial connection at 9600 bps:
}
void loop()
{
  htSensor = DHT.read22(LM35_pin);
  // read analog voltage from LM35, convert to digital and use formula
  // Converts the analog voltage from LM35 to digital reading where 5
  // is the supply voltage 5V
  // prints on serial monitor
  Serial.print("Temperature from LM35: ");
  // Prints current temperature on Serial Monitor
  LM35_temp = DHT.temperature;
  Serial.print((float)LM35_temp); 
  Serial.println(" *C");
  delay(500); // 5 seconds delay before taking the new reading
}