#include <Servo.h>
#define DATAIN 0
Servo servo1; //define object

void setup() 
{
  servo1.attach(5); //connect pin5 to servo1
  pinMode(3,OUTPUT); //define i/o 3 is for Relay control
  
  Serial.begin(9600);
  randomSeed(analogRead(DATAIN)); //let the random funtion start at renadom point
  
  digitalWrite(3,HIGH); //this section is control the Relay connect and stop and connet and stop. By this way the Ereader device can turn on without push on power buttom
  delay(5000);
  digitalWrite(3,LOW);
  delay(15000);
  digitalWrite(3,HIGH);
  delay(10000);
}

void loop() 
{
  servo1.write(45); //write 45 degree to servo
  int tingzi=random(2666,6666);
  Serial.println(tingzi);  // it is no related to auto-punch funtion, it is just for programing to monitor the delay.
  delay(tingzi); //delay random
  servo1.write(-45);
  delay(100); 
}
