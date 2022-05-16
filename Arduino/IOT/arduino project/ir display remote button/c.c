#include <IRremote.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 7, 6, 5, 4, 3);
IRrecv irrecv(9);
decode_results results;
unsigned long key_value = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  attachInterrupt(0, ResetScreen, RISING);
}

void loop(){
  if (irrecv.decode(&results)){
 
        if (results.value == 0XFFFFFFFF)
          results.value = key_value;

        switch(results.value){
          case 0xFD00FF:
          lcd.print("Power     ");
          lcd.setCursor(0, 0);
          break;
          case 0xFD807F:
          lcd.print("Vol+      ");
          lcd.setCursor(0, 0);
          break;
          case 0xFD40BF:
          lcd.print("FUNC/STOP ");
          lcd.setCursor(0, 0);
          break;
          case 0xFD20DF:
          lcd.print("|<<       ");
          lcd.setCursor(0, 0);
          break;
          case 0xFDA05F:
          lcd.print(">||       ");
          lcd.setCursor(0, 0);
          break ;  
          case 0xFD609F:
          lcd.print(">>|       ");
          lcd.setCursor(0, 0);
          break ;               
          case 0xFD10EF:
          lcd.print("Down Arrow");
          lcd.setCursor(0, 0);
          break ;  
          case 0xFD906F:
          lcd.print("Vol-      ");
          lcd.setCursor(0, 0);
          break ;  
          case 0xFD50AF:
          lcd.print("Up Arrow  ");
          lcd.setCursor(0, 0);
          break ;  
          case 0xFD30CF:
          lcd.print("0         ");
          lcd.setCursor(0, 0);
          break ;  
          case 0xFDB04F:
          lcd.print("EQ        ");
          lcd.setCursor(0, 0);
          break ;
          case 0xFD708F:
          lcd.print("ST/REPT   ");
          lcd.setCursor(0, 0);
          break ;
          case 0xFD08F7:
          lcd.print("1         ");
          lcd.setCursor(0, 0);
          break ;
          case 0xFD8877:
          lcd.print("2         ");
          lcd.setCursor(0, 0);
          break ;
          case 0xFD48B7:
          lcd.print("3         ");
          lcd.setCursor(0, 0);
          break ;
          case 0xFD28D7:
          lcd.print("4         ");
          lcd.setCursor(0, 0);
          break ;
          case 0xFDA857:
          lcd.print("5         ");
          lcd.setCursor(0, 0);
          break ;
          case 0xFD6897:
          lcd.print("6         ");
          lcd.setCursor(0, 0);
          break ;
          case 0xFD18E7:
          lcd.print("7         ");
          lcd.setCursor(0, 0);
          break ;
          case 0xFD9867:
          lcd.print("8         ");
          lcd.setCursor(0, 0);
          break ;
          case 0xFD58A7:
          lcd.print("9         ");
          lcd.setCursor(0, 0);
          break ;      
        }
        key_value = results.value;
        irrecv.resume(); 
  }
}

void ResetScreen() {
  lcd.print("          ");
  lcd.setCursor(0, 0);
}
