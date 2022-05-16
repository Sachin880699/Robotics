
#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;

int potpin1 = A0;  // analog pin used to connect the potentiometer
int val1;    // variable to read the value from the analog pin
int potpin2 = A1;  // analog pin used to connect the potentiometer
int val2; 
void setup()
{
  myservo1.attach(3);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(5);
}

void loop() 
{ 
  val1 = analogRead(potpin1);            // reads the value of the potentiometer (value between 0 and 1023) 
  val1 = map(val1, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
  myservo1.write(val1);                  // sets the servo position according to the scaled value 
  
  val2 = analogRead(potpin2);            // reads the value of the potentiometer (value between 0 and 1023) 
  val2 = map(val2, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
  myservo2.write(val2); 
  delay(15);                           // waits for the servo to get there 
} 

