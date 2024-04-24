/***********************************************************
Authors: Hannah Bidstrup og Jonas Peder Iversen
Rover Project, IT-Teknolog
***********************************************************/


//Libraries:
////////////////////////////////////////////////////////////////////////////////////
//Thermo couple library:
#include "max6675.h"
////////////////////////////////////////////////////////////////////////////////////


//Pin overview (only change pins here and never in the code!):
////////////////////////////////////////////////////////////////////////////////////
//SPI pins:
#define MISO_pin 50
#define MOSI_pin 51
#define SCK_pin  52
#define thermocouple_CS_pin 53
//Motor PWM pins:
#define right_Motor_PWN_pin 7             //Right Motor = Motor 1 = Motor A
#define left_Motor_PWN_pin 8              //Left Motor = Motor 2 = Motor B
//Motor direction pins:
#define right_motor_direction_1_pin 2
#define right_motor_direction_2_pin 3
#define left_motor_direction_1_pin 4
#define left_motor_direction_2_pin 5
//Joystick switch and axis pins:
#define joystick_switch_pin 6
//joystick_x_axis_pin A0
//joystick_y_axis_pin A1
////////////////////////////////////////////////////////////////////////////////////


//Set software or hardware PWM:
////////////////////////////////////////////////////////////////////////////////////
#define hardware_PWM true      //false = software PWM
////////////////////////////////////////////////////////////////////////////////////


//Variable defines and declarations :
////////////////////////////////////////////////////////////////////////////////////
//Temperature measurement interval in seconds:
#define temperature_measurement_interval_in_seconds 60
//Loop delay in milliseonds eg. update delay for joystick inputs and motor updates:
#define loop_update_delay_in_milliseconds 100
//Motor frequency:
#define motor_PWM_frequency 25000
//Joystick global variables:
int x_direction = 0;
int y_direction = 0;
//Variable used by multiple functions for controlling motor frequency and speed:
int ICR4Variable = 0;
////////////////////////////////////////////////////////////////////////////////////


//Motor offsets, the motors dont work at low duty cycles when running on 7,5V and 
//they dont act the same, therefore offsets are needed:
////////////////////////////////////////////////////////////////////////////////////
#define right_motor_offset 90     //Doesnt run at all under right_motor_offset/255 pwn input
#define left_motor_offset 90      //Doesnt run at all under left_motor_offset/255 pwn input
////////////////////////////////////////////////////////////////////////////////////


//Thermo couple object creation:
////////////////////////////////////////////////////////////////////////////////////
MAX6675 thermo_couple(SCK_pin, thermocouple_CS_pin, MISO_pin);
////////////////////////////////////////////////////////////////////////////////////


//Serial connection defines:
////////////////////////////////////////////////////////////////////////////////////
//Serial Baud rates:
#define serial0_baud_rate 9600
#define serial1_baud_rate 9600
////////////////////////////////////////////////////////////////////////////////////

//Main functions (setup and loop):
////////////////////////////////////////////////////////////////////////////////////
void setup(){
  init_serial();
  init_motors();
  init_joystick();
}
void loop(){
  get_joystick_input();
  update_motors();
  get_thermo_couple_temperature_and_write_to_raspberry_pi();
  delay(loop_update_delay_in_milliseconds - 5);
}
////////////////////////////////////////////////////////////////////////////////////


//Motor handling functions:
////////////////////////////////////////////////////////////////////////////////////
void init_motors(){
  //PWM motor pins:
  pinMode(right_Motor_PWN_pin, OUTPUT);
  pinMode(left_Motor_PWN_pin, OUTPUT);

  //Motor direction pins:
  pinMode(right_motor_direction_1_pin, OUTPUT);
  pinMode(right_motor_direction_2_pin, OUTPUT);
  pinMode(left_motor_direction_1_pin, OUTPUT);
  pinMode(left_motor_direction_2_pin, OUTPUT);

  //Change pin 7 and 8 to PWM pins:
  analogWrite(right_Motor_PWN_pin, 128);
  analogWrite(left_Motor_PWN_pin, 128);

  //Set hardware PWM frequency:
  if(hardware_PWM == true){
    set_motor_frequency(motor_PWM_frequency);
  }
}
void set_right_motor_direction(String direction){
  if(direction == "backwards"){
    digitalWrite(right_motor_direction_1_pin, LOW);
    digitalWrite(right_motor_direction_2_pin, HIGH);
  }else if(direction == "forwards"){
    digitalWrite(right_motor_direction_1_pin, HIGH);
    digitalWrite(right_motor_direction_2_pin, LOW);
  }
}
void set_left_motor_direction(String direction){
  if(direction == "backwards"){
    digitalWrite(left_motor_direction_1_pin, HIGH);
    digitalWrite(left_motor_direction_2_pin, LOW);
  }else if(direction == "forwards"){
    digitalWrite(left_motor_direction_1_pin, LOW);
    digitalWrite(left_motor_direction_2_pin, HIGH);
  }
}
void set_right_motor_speed(int percentage_duty_cycle) {
  if(hardware_PWM == true){
    float offset_duty_cycle = map(percentage_duty_cycle, 0, 100, (right_motor_offset / 255), 100);
    OCR4B  = ICR4Variable * ((float)(offset_duty_cycle / 100.0));
  }else{
    float offset_duty_cycle = map(percentage_duty_cycle, 0, 100, (left_motor_offset / 255), 100);
    int converted_duty_cycle = round(float(offset_duty_cycle) * 2.55);
    Serial.println(converted_duty_cycle);
    analogWrite(right_Motor_PWN_pin, converted_duty_cycle);
  }
}
void set_left_motor_speed(int percentage_duty_cycle) {
  if(hardware_PWM == true){
    float offset_duty_cycle = map(percentage_duty_cycle, 0, 100, (left_motor_offset / 255), 100);
    OCR4C = ICR4Variable * ((float)(percentage_duty_cycle / 100.0));
  }else{
    float offset_duty_cycle = map(percentage_duty_cycle, 0, 100, (left_motor_offset / 255), 100);
    int converted_duty_cycle = round(float(offset_duty_cycle) * 2.55);
    analogWrite(left_Motor_PWN_pin, converted_duty_cycle);
  }
}
void set_motor_frequency(int frequency){
  noInterrupts();
  TCCR4A = 0; // clear register
  TCCR4B = 0; // clear register
  TCNT4 = 0; // clear register

  ICR4 = (F_CPU / frequency) / 2;
  ICR4Variable = ICR4;

  TCCR4A = _BV(COM4C1) | _BV(COM4B1)| _BV(WGM41);       //COM4C1 = pin 8, COM4B1 = pin 7
  TCCR4B = _BV(WGM43) | _BV(CS40);
  interrupts();
}
void update_motors(){
  //Joystick up and down = throttle eg. how high duty cycle the motors run on
  //Joystick side to side = ratio of which motor gets the throttle.
  int throttle = abs(x_direction);
  //Control if going backwards, forwards or standing still:
  if(x_direction > 3){
    set_right_motor_direction("forwards");
    set_left_motor_direction("forwards");
    if(y_direction > 0){
    set_right_motor_speed(throttle * ((100 - float(y_direction)) / 100.0));
    set_left_motor_speed(throttle);
    }else if(y_direction < 0){
    set_right_motor_speed(throttle);
    set_left_motor_speed(throttle * ((100 + float(y_direction)) / 100.0));
    }
  }else if(x_direction < -3){
    set_right_motor_direction("backwards");
    set_left_motor_direction("backwards");
      if(y_direction > 0){
      set_right_motor_speed(throttle * ((100 - float(y_direction)) / 100.0));
      set_left_motor_speed(throttle);
    }else if(y_direction < 0){
      set_right_motor_speed(throttle);
      set_left_motor_speed(throttle * ((100 + float(y_direction)) / 100.0));
    }
  }else{
    set_right_motor_speed(0);
    set_left_motor_speed(0);
  }
}
////////////////////////////////////////////////////////////////////////////////////


//Joystick handling functions:
////////////////////////////////////////////////////////////////////////////////////
void init_joystick(){
  //Joystick pin setup:
  pinMode(joystick_switch_pin, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}
void get_joystick_input(){
  int x_sum = 0;
  int y_sum = 0;

  for(int i = 0; i < 5; i++){
    x_sum += analogRead(A0);
    y_sum += analogRead(A1);
    delay(1);
  }

  x_direction = map((x_sum / 5), 0, 1023, -100, 100);
  y_direction = map((y_sum / 5), 0, 1023, -100, 100);
}
////////////////////////////////////////////////////////////////////////////////////


//Serial handling functions:
////////////////////////////////////////////////////////////////////////////////////
void init_serial(){
  Serial.begin(serial0_baud_rate);
  Serial1.begin(serial1_baud_rate);
}
////////////////////////////////////////////////////////////////////////////////////


//Thermo couple handling functions:
////////////////////////////////////////////////////////////////////////////////////
float get_thermo_couple_temperature(){
  return (thermo_couple.readCelsius());
}
void get_thermo_couple_temperature_and_write_to_raspberry_pi(){
  Serial1.print(get_thermo_couple_temperature());
}
////////////////////////////////////////////////////////////////////////////////////