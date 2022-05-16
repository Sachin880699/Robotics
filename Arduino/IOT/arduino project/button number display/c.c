// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  if (digitalRead(A0) == HIGH) {
    lcd.print("Button 1");
    }
  if (digitalRead(A1) == HIGH) {
    lcd.print("Button 2");
    }
  if (digitalRead(A2) == HIGH) {
    lcd.print("Button 3");
    }
}
 
