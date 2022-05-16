//Arduino Keypad Lock 
//PlEaSe REaD aLL!!!!!!!(*&^$#&0837w97_*W37-5*(#$&%*#&(*@&_-)
//PlEaSe REaD aLL!!!!!!!(*&^$#&0837w97_*W37-5*(#$&%*#&(*@&_-)
//PlEaSe REaD aLL!!!!!!!(*&^$#&0837w97_*W37-5*(#$&%*#&(*@&_-)
//PlEaSe REaD aLL!!!!!!!(*&^$#&0837w97_*W37-5*(#$&%*#&(*@&_-)
//MADE BY ELIS CHESARU
//IF YOU COPY THE CODE PLEASE LEAVE US THE DESCRIPTION AND- 
//-PLEASE DO NOT ERASE OR MODIFY THE DESCRIPTION IF YOU CAN.
//ENJOY! WITH DEAR, ELIS.
//Default password is: 723
//PRESS * OR # TO LOCK
//IF DO NOT WORK, INSIST WITH PASSWORD.

//Cable Configuration:
//PIN ROW 1- DIGITAL 8
//PIN ROW 2- DIGITAL 7
//PIN ROW 3- DIGITAL 6
//PIN ROW 4- DIGITAL 9
 
//PIN COLUMN 1- DIGITAL 5
//PIN COLUMN 2- DIGITAL 4
//PIN COLUMN 3- DIGITAL 3
//PIN COLUMN 4- DIGITAL 2

//PIN LED GREEN- DIGITAL 13
//PIN LED RED- DIGITAL 12
//GROUND FROM LEDS TO A 220 OHM RESISTOR CONECTED WITH GROUND
//YOU CAN USE A RGB LED OR TWO DIFERENT LEDS.EXEMPLE: RED AND GREEN

//SERVO PIN SIGNAL- DIGITAL 11
//SERVO PIN GROUND- GROUND
//SERVO PIN VCC/POWER- 5V
#include <Servo.h>
#include <Keypad.h>

Servo ServoMotor;
char* password = "723"; //From there you can change the password
//-but be careful of how many figures it is formed.
//Look below to choose the number of password digits.
int position = 0;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

byte rowPins[ROWS] = { 8, 7, 6, 9 };
byte colPins[COLS] = { 5, 4, 3, 2 };
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int RedpinLock = 12; // RED LED PIN FOR STATUS. RED=LOCKED
int GreenpinUnlock = 13;//GREEN LED PIN FOR STATUS. GREEEN=UNLOCKED

void setup()
{
pinMode(RedpinLock, OUTPUT);
pinMode(GreenpinUnlock, OUTPUT);
ServoMotor.attach(11); //FROM HERE YOU CAN CHANGE SERVO SIGNAL
                       //PIN
LockedPosition(true);
}

void loop()
{
char key = keypad.getKey();
if (key == '*' || key == '#')
{
position = 0;
LockedPosition(true);
}
if (key == password[position])
{
position ++;
}
if (position == 3) //CHANGES TO CHANGE THE NUMBER OF -
                   //-DIGITS FROM PASSWORD
{
LockedPosition(false);
}
delay(100);
}
void LockedPosition(int locked)
{
if (locked)
{
digitalWrite(RedpinLock, HIGH);
digitalWrite(GreenpinUnlock, LOW);
ServoMotor.write(11);
}
else
{
digitalWrite(RedpinLock, LOW);
digitalWrite(GreenpinUnlock, HIGH);
ServoMotor.write(360);  //FROM HERE YOU CAN CHANGE THE SERVO-
                        //-ROTATION STEPS
  //DEFAULT IS: 360
}
}

