
#include <Servo.h>

Servo myservo;  // create servo object to control a servo



void setup()
{
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
}

void loop() 
{ 

  myservo.write(0); 
  delay(2000);  
  myservo.write(90);  
  delay(2000);  
  myservo.write(180); 
  delay(2000); 
  myservo.write(90);   
  delay(2000); 
} 

