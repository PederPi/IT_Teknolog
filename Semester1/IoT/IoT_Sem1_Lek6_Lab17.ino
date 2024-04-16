
/*
 example with buzzer
*/



int buzzerPin = 6; // outpu pin -> to passive buzzer
int i;

void setup() {
  Serial.begin(115200); 
  Serial.println("Example - Passive Buzzer");
  pinMode(buzzerPin, OUTPUT);
}



void loop() { 


  for (i = 0; i <120; i ++) // outputs sound 1
  {
    digitalWrite (buzzerPin, HIGH) ;// send pulse
    delay (1) ;// delay 1 ms
    digitalWrite (buzzerPin, LOW) ; // do not send pulse
    delay (1) ;// delay 1 ms
  }


  for (i = 0; i <80; i ++) // outputs sound 2
  {
    digitalWrite (buzzerPin, HIGH) ;// send pulse
    delay (2) ;// delay 2ms
    digitalWrite (buzzerPin, LOW) ; // do not send pulse
    delay (2) ;// delay 2ms
  }

}


 