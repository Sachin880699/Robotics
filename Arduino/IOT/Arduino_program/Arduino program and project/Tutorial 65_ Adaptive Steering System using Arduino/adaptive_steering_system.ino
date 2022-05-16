
#include <Servo.h>
#include <LiquidCrystal.h>
Servo servo;   
int pot = 0;  

int val;    

LiquidCrystal lcd(7, 9, 10, 11, 12, 13);

byte v1[8] = {
 B11111, 
 B11111, 
 B11111, 
 B11111,   
 B11111, 
 B11111,
 B11111,
 B11111 
};

void setup() {
  lcd.createChar(0, v1);
 
  lcd.begin(16, 2);  
  servo.attach(3);    
}

void loop() {
  
  
  val = analogRead(pot); 
  val = map(val, 0, 1023, 0, 180);
  
  servo.write(val);      
    
   lcd.setCursor(0,0);
   lcd.write(byte(0));
  
    lcd.setCursor(7,1);
    lcd.print(val);

  

  }
