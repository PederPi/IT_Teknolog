//Libraries:
#include <SPI.h>        //Libraries for handling SD card reader
#include <SD.h>
#include <Wire.h>       //Needed for I2C communication.
#include <RTClib.h>     //For handling the Real Time Clock
#include <DHT.h>        //Library for handling the temperature and humidity sensor

//Defines and declarations. 
#define DHT_IN_PIN 30                    //Data pin from DHT inside sensor
#define DHT_OUT_PIN 40                   //Data pin from DHT outside sensor
#define CHIPSELECT_PIN 53                //Chip select pin for the sd card reader.
#define LOGGING_INTERVAL 1              //Interval between logging data to file. (Warning do not change!)
#define LOGFILE_NAME "DATALOG.TXT"       //Name of the file crated with logging data
#define SENSOR_TYPE DHT22                //Set the temperature and humidity sensor type.
#define LIGHT_SENSOR_PIN A0              //Set pin for light sensor
const bool DEBUG = true;                 //Enable or disable code debugging, if enables will send information to serial.
RTC_DS3231 rtc;                          //Create object of type: "RTC_DS3231" with name: "rtc"
DHT dht_OUT(DHT_OUT_PIN, SENSOR_TYPE);   //Create object of type: "DHT" with name: "dht_OUT"
DHT dht_IN(DHT_IN_PIN, SENSOR_TYPE);     //Create object of type: "DHT" with name: "dht_IN"

//Function:    Setup makes sure to initialize the needed ressources before logging begins.
void setup() {
  if(DEBUG){
    serialInit();   //Initialize the serial connection.
  }
  cardInit();     //Initialize the SD card reader.
  rtcInit();      //Initialize the RTC(Real Time Clock).
  sensorInit();   //Initialize the Temperature and humidity sensor.
  pinMode(A0, INPUT);
}

//Main:    
void loop() {
  checkTime();                          //Put the Arduino to sleep.
  logDataToFile(LOGFILE_NAME);      //Get data from DHT and log them to file on SD card. Parameter: Log text file name
}

//Function:    Initialize the SD card.
void cardInit(){
  SD.begin(CHIPSELECT_PIN);   //Initialize the SD card, begins the use of the SPI pins.

  if(DEBUG){
    Serial.print("Initializing SD Card: ");
    Serial.flush();
     if(!SD.begin(CHIPSELECT_PIN)){                   //If no SD card reader is detected on the pin, print error message.
      Serial.println("          Failed");             //Else print confirmation message.
      Serial.flush();
      while (1);
    }
    Serial.println("          Success");
    Serial.flush();
  }
}

//Function:    Initialize Serial Connection.
void serialInit(){
  Serial.begin(9600);    //Initialize the serial connection with the given BAUD rate.
  while (!Serial) {             //Loop until a serial connection is detected.
    ;
  }

  if(DEBUG){
    Serial.println("Initializing Serial Connection: Success");
  }
}

//Function:    Initialize the real time clock module.
void rtcInit(){
  Wire.begin();                                     //Initialize the wire library and join the I2C bus as a controller.
  rtc.begin();                                      //Initialize the connection to the Real Time Clock.
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));   //Set the time on the RTC using system time.
 
  if(DEBUG){
    Serial.print("Initializing RTC: ");
    if (!rtc.begin()){                              //Checks if the RTC initialization and connection is working.
      Serial.println("             Failed");
      abort();
    }
    else{
      Serial.println("              Success");
    }
    Serial.flush();
  }
}

//Function:    Initialize the humidity and temperature sensor.
void sensorInit(){
  dht_IN.begin();    //Initialize DHT sensor
  dht_OUT.begin();    //Initialize DHT sensor

  if(DEBUG){
    Serial.print("Initializing DHT_IN Sensor: ");
    if (isnan(dht_IN.readHumidity()) || isnan(dht_IN.readTemperature()) || isnan(dht_IN.readTemperature(true))) {
      Serial.println("    Failed");
    }
    else{
      Serial.println("    Success");
    }
    Serial.flush();
    Serial.print("Initializing DHT_OUT Sensor: ");
    if (isnan(dht_OUT.readHumidity()) || isnan(dht_OUT.readTemperature()) || isnan(dht_OUT.readTemperature(true))) {
      Serial.println("   Failed");
    }
    else{
      Serial.println("   Success");
    }
    Serial.flush();
  }
}

//Function:    Reads temperature and humidity from sensor and returns it as a string.
String getTemperatureAndHumidity(){
  String temperatureAndHumidity = "";
  temperatureAndHumidity += int(dht_IN.readTemperature() * 10);  //Get temperature from the sensor and add the data to string.
  temperatureAndHumidity += ",";                    
  temperatureAndHumidity += int(dht_IN.readHumidity() * 10);     //Get humidity from sensor and add the data to string.
  temperatureAndHumidity += ",";   
  temperatureAndHumidity += int(dht_OUT.readTemperature() * 10);  //Get temperature from the sensor and add the data to string.
  temperatureAndHumidity += ",";                    
  temperatureAndHumidity += int(dht_OUT.readHumidity() * 10);     //Get humidity from sensor and add the data to string.
  temperatureAndHumidity += ",";   
  temperatureAndHumidity += analogRead(A0);
  temperatureAndHumidity += ",";   
  return temperatureAndHumidity;                    //Return the string of combines temperature and humidity data.
}

//Function:    Reads current time from the real time clock module and returns it as a string.
String getDateTime(){
  String dateTime = "";
  DateTime now = rtc.now();
  dateTime += now.year(), DEC;    //Get current year and add to string.
  dateTime += "-";
  dateTime += now.month(), DEC;   //Get current month and add to string.
  dateTime += "-";
  dateTime += now.day(), DEC;     //Get current day and add to string.
  dateTime += ",";
  dateTime += now.hour(), DEC;    //Get current hour and add to string.
  dateTime += ":";
  dateTime += now.minute(), DEC;  //Get current minute and add to string.
  dateTime += ":";
  dateTime += now.second(), DEC;  //Get current second and add to string.
  dateTime += ",";
  return dateTime;                //Return the combines string with date information.
}

//Function:    Writes the logged time and sensor data to a file on the SD card.
void logDataToFile(String fileName){
  String dataString = "";
  dataString += getDateTime();                    //Get current datetime and add to string.
  dataString += getTemperatureAndHumidity();      //Get sensor data and add to string.
  File dataFile = SD.open(fileName, FILE_WRITE);  //Open datalogger file and prepare to write to file.
  dataFile.println(dataString);                   //Write data stored in string to file.
  dataFile.close();                               //Close datalogger file.
  if(DEBUG){
    Serial.print("Data logged to file: ");
    Serial.println(dataString);
    Serial.flush();
  }
  delay(5000);
}

//Function:    Currently unused.
void checkTime(){
  bool run = 1;
  while(run){
    DateTime now = rtc.now();
    if(now.second() == 0 && now.minute() % LOGGING_INTERVAL == 0){
      run = 0;
    }else{
      delay(500);
    }
  }
}