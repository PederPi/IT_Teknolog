// EMB2
// lab01.ino
/*	
MAX6675

*/
#include <Wire.h> 
#include <SPI.h>

#define MAX6675_CS 53
#define MAX6675_SO 50
#define MAX6675_SCK 52


void setup() {
  Serial.begin(9600);

  pinMode(MAX6675_CS, OUTPUT); // CS as output
  pinMode(MAX6675_SCK, OUTPUT); // SCK as output
  pinMode(MAX6675_SO, INPUT); // SO as intput

  delay(250);
 
}

void loop() {
  float temperature_read = read_K_Thermocouple(); 
  
  Serial.print("Temperature: ");
  Serial.println(temperature_read);
  
  delay(300);
}

//software implementation SPI
double read_K_Thermocouple() {

  uint16_t value;
  

  digitalWrite(MAX6675_CS, LOW);
  _delay_us(1);

  // Read in 16 bits,
  // Bit = description
  //  ?? check documentation
  
  value = shiftIn(MAX6675_SO, MAX6675_SCK, MSBFIRST);
  value <<= 8;
  value |= shiftIn(MAX6675_SO, MAX6675_SCK, MSBFIRST);
  
  digitalWrite(MAX6675_CS, HIGH);


  value >>= 3;
  return value * 0.25;
}


