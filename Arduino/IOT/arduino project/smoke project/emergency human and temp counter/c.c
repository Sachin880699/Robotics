#include<LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int const GAS = A5;
float TEMP=A4;
const int in=A1;
const int out=A0;
int BUZZER = 13;
int GLED = 6;
int YLED = 5;
int OLED = 4;
int RLED = 3;

int count=0;

float degreesC =0;
float degreesF =0;

void IN()
{
    count++;
    lcd.clear();
    lcd.print("Person Inside:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
}

void OUT()
{
  count--;
    lcd.clear();
    lcd.print("Person Inside:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
}

void setup(){
	pinMode(BUZZER, OUTPUT);
	pinMode(GLED, OUTPUT);
	pinMode(YLED, OUTPUT);
	pinMode(OLED, OUTPUT);
	pinMode(RLED, OUTPUT);
    Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Visitor Counter");
  delay(1000);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  lcd.clear();
  lcd.print("Person Inside:");
  lcd.setCursor(0,1);
  lcd.print(count);
}

void loop(){

  if(digitalRead(in))
  	IN();
  if(digitalRead(out))
  	OUT();

  int reading = analogRead(A4);
  float voltage = reading*5.0;
  voltage /= 1024.0;
 
  float degreesC = (voltage - 0.5) * 100; 
  float degreesF = degreesC * (9.0/5.0) + 32.0;
  
  Serial.print("  deg C: ");
  Serial.print(degreesC);
  Serial.print("  deg F: ");
  Serial.println(degreesF);
  Serial.println(); 
  	delay(500);
  
	  
    int value = analogRead(GAS);
    	value = map(value, 300, 750, 0, 100);
    digitalWrite(GLED, HIGH);
    digitalWrite(YLED, value >= 30 || degreesC >= 50 ? HIGH : LOW);
    digitalWrite(OLED, value >= 50 || degreesC >= 70 ? HIGH : LOW);
    digitalWrite(RLED, value >= 80 || degreesC >= 90 ? HIGH : LOW);

  if ((value > 30 && value < 50) || (degreesC >= 50 && degreesC <= 70))
  {
    tone(BUZZER, 500, 1000);
     }
  if ((value > 50 && value < 80) || (degreesC >= 70 && degreesC <= 90))
  {
    tone(BUZZER, 750, 1000);
     }
  if (value > 80 || degreesC >= 90)
  {
    tone(BUZZER, 1000, 1000);
     }
}
