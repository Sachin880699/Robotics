#define BUTTON_PIN    2
#define LAMP_PIN      5
 
bool lampState = false;
//  we made a variable which shows us the current state of lamp.
bool wasButtonDown = false;
// this variable show us the previous state of button.when before the button was pressed or not.
 
void setup()
{
    pinMode(BUTTON_PIN, INPUT);
    pinMode(LAMP_PIN, OUTPUT);
}
 
void loop()
{
	bool isButtonDown = digitalRead(BUTTON_PIN);
  // we are reading the current state of the button.
	if (isButtonDown && !wasButtonDown) {
        lampState = !lampState;
    	delay(10);
	// if the button is pressed,it will gives us high and invert the "wasButtonDown" will also gives us high so
    // the condition will be true and lampstate will become invert means from low to high.
      //delay is good to give to well read the button.
    }
 
    wasButtonDown = isButtonDown;
  //m above line is very tricly... wasButtonDown will have high value when the moment button is pressed but 
  //when we release the button it will again have low value because the isButtonDown will become low.
  // so next time when we press the button,the wasButtonDown value will again be LOW.
    digitalWrite(LAMP_PIN, lampState);
}

