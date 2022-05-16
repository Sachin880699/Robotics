//Keypad 4x4 e LCD
#include <SPI.h>
#include <Keypad.h>
#include <LiquidCrystal.h>


const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {4, 3, 2, A1}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5, A2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
char key = keypad.getKey();

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

//VARIABLE FOR FUNCTIONS:
char var;
char bt_enter = '*';
char bt_cancel = '#';
char bt_menu = 'C';
char bt_codebomb = 'B';
char bt_timebomb = 'A';
char bt_alarme = 'D';
char gamemod;
char var1;
char cod1;
char cod2;
char cod3;
char cod4;
char cod5;
char vcod1;
char vcod2;
char vcod3;
char vcod4;
char vcod5;


void setup() {
  //Sets the number of columns and LCD lines
  lcd.begin(16, 2);
  //Cleans the screen
  lcd.clear();
  //Position the cursor in column 0, line 0;
  lcd.setCursor(0, 0);
  //Send the text in quotation marks to the LCD
  lcd.setCursor(4, 0);
  lcd.print(" ");
  lcd.setCursor(0, 3);
  lcd.print("----Fake Bomb----");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Game Will Be");
  lcd.setCursor(0, 1);
  lcd.print("Starting in 3");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("Starting in 2");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("Starting in 1");
  delay(1000);
  lcd.clear();

}

void loop()
{
  menuPrincipal();
}

//FUNCTIONS AND GAMES

void menuPrincipal()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  Select Game"); // Select type of mission
  lcd.setCursor(1, 1);
  lcd.print("TIME=A CODE=B");
  var = keypad.waitForKey();
  if (var == bt_timebomb)
  {
    gamemod = 0;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("------GAME------");
    lcd.setCursor(1, 1);
    lcd.print("--Time Bomb--");
    delay(2000);
    TimeMod();
  }
  if (var == bt_codebomb)
  {
    gamemod = 1;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("------GAME------");
    lcd.setCursor(1, 1);
    lcd.print("--Bomb Code--");
    delay(2000);
    CodeMod();
  }
  if (var == bt_alarme)
  {
    AlarmeMod();
  }
}

void TimeMod()
{
  int LedVerm = A0;          //Function set time (Start)
  pinMode(LedVerm, OUTPUT);
  int LedAma = A3;
  pinMode(LedAma, OUTPUT);
  int LedVer = 1;
  pinMode(LedVer, OUTPUT);
  int stopPin = A5;
  pinMode(stopPin, INPUT);
  int som = A4;
  pinMode(som, OUTPUT);
  int stop = 0;
  char var1;
  char restart;
  char estado;
  char settimeH0;
  char settimeH1;
  char settimeM0;
  char settimeM1;
  char settimeS0;
  char settimeS1;
  int segundo;
  lcd.clear();
  lcd.print("Set Time");
  lcd.setCursor(8, 0);
  lcd.print("-Clear=#");
  lcd.setCursor(8, 1);
  lcd.print("-Enter=*");
  lcd.setCursor(0, 1);
  lcd.print("X");
  lcd.setCursor(1, 1);
  lcd.print("X");
  lcd.setCursor(2, 1);
  lcd.print(":");
  lcd.setCursor(3, 1);
  lcd.print("X");
  lcd.setCursor(4, 1);
  lcd.print("X");
  lcd.setCursor(5, 1);
  lcd.print(":");
  lcd.setCursor(6, 1);
  lcd.print("X");
  lcd.setCursor(7, 1);
  lcd.print("X");
  settimeH0 = keypad.waitForKey();                               //Passa a salvar o tempo nas variaveis
  tone(som, 800, 100);
  if (settimeH0 != NO_KEY)
  {
    lcd.setCursor(0, 1);
    lcd.print(settimeH0);
    settimeH1 = keypad.waitForKey();
    tone(som, 800, 100);
    lcd.setCursor(1, 1);
    lcd.print(settimeH1);
    settimeM0 = keypad.waitForKey();
    tone(som, 800, 100);
    lcd.setCursor(3, 1);
    lcd.print(settimeM0);
    settimeM1 = keypad.waitForKey();
    tone(som, 800, 100);
    lcd.setCursor(4, 1);
    lcd.print(settimeM1);
    settimeS0 = keypad.waitForKey();
    tone(som, 800, 100);
    lcd.setCursor(6, 1);
    lcd.print(settimeS0);
    settimeS1 = keypad.waitForKey();
    tone(som, 800, 100);
    lcd.setCursor(7, 1);
    lcd.print(settimeS1);

    var1 = keypad.waitForKey();                               //Inicia o jogo com a contagem regressiva em tela
    tone(som, 800, 100);
    if (var1 == bt_enter)

    { int j;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("-----BOMB------");
      lcd.setCursor(4, 1);
      lcd.print(settimeH0);
      lcd.setCursor(5, 1);
      lcd.print(settimeH1);
      lcd.setCursor(6, 1);
      lcd.print(":");
      lcd.setCursor(7, 1);
      lcd.print(settimeM0);
      lcd.setCursor(8, 1);
      lcd.print(settimeM1);
      lcd.setCursor(9, 1);
      lcd.print(":");
      lcd.setCursor(10, 1);
      lcd.print(settimeS0);
      lcd.setCursor(11, 1);
      lcd.print(settimeS1);
      estado = 1;                                                       //Coloca o estado da bomba como ativado
      segundo = 1000;
      stop = digitalRead(stopPin);
      j = 5;
      while (estado == 1)               //Count Loop
      { int i = -1;

        while (stop != digitalRead(stopPin) && gamemod == 1)   //Interrompe o contador para abrir o modo de desarme-----------------------------------------------------------------
        {

          digitalWrite(LedAma, LOW);
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("Password: ");
          if (j > 0) {
            lcd.setCursor(0, 0); lcd.print("Attempts");
            lcd.setCursor(15, 0);  j--;  delay(10); lcd.print(j);
          }
          vcod1 = keypad.getKey();
          unsigned long startedWaiting = millis();
          while (vcod1 == NO_KEY && millis() - startedWaiting <= 5000)
                    {
          vcod1 = keypad.getKey();
          }
          lcd.print(vcod1);
          lcd.setCursor(9, 1);
          lcd.print("*");
          {
          }
          vcod2 = keypad.getKey();
          startedWaiting = millis();
          while (vcod2 == NO_KEY && millis() - startedWaiting <= 500)
          {
          vcod2 = keypad.getKey();
          }
          lcd.print(vcod2);
          lcd.setCursor(10, 1);
          lcd.print("*");
          {
          }
          vcod3 = keypad.getKey();
          startedWaiting = millis();
          while (vcod3 == NO_KEY && millis() - startedWaiting <= 500)
          {
          vcod3 = keypad.getKey();
          }
          lcd.print(vcod3);
          lcd.setCursor(11, 1);
          lcd.print("*");
          {
          }
          vcod4 = keypad.getKey();
          startedWaiting = millis();
          while (vcod4 == NO_KEY && millis() - startedWaiting <= 500)
          {
          vcod4 = keypad.getKey();
          }
          lcd.print(vcod4);
          lcd.setCursor(12, 1);
          lcd.print("*");
          {
          }
          vcod5 = keypad.getKey();
          startedWaiting = millis();
          while (vcod5 == NO_KEY && millis() - startedWaiting <= 500)
          {
          vcod5 = keypad.getKey();
          }
          lcd.print(vcod5);
          lcd.setCursor(13, 1);
          lcd.print("*");
          if (cod1 != vcod1 || cod2 != vcod2 || cod3 != vcod3 || cod4 != vcod4 || cod5 != vcod5)
          {
            segundo = segundo - 200;
            lcd.setCursor(0, 1);
            lcd.print("Invalid Password");
            delay(1000);
          }
          if (cod1 == vcod1 && cod2 == vcod2 && cod3 == vcod3 && cod4 == vcod4 && cod5 == vcod5)
          {
            digitalWrite(LedVer, HIGH);
            estado = 0;                          //If it is to disarm the pump it changes check state
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("--Deactivated!--");
            lcd.setCursor(0, 1);
            lcd.print("");
            delay(3000);
            lcd.setCursor(0, 0);
            lcd.print("Restart on/off");      //Reset on and off for next game
            lcd.setCursor(0, 1);
            lcd.print("New=B-- Menu=C--");      //release menu to restart the game or return to the mode menu
            digitalWrite(LedVerm, LOW);     //Ledverm (LedVerm)
            restart = keypad.waitForKey();
          }
        }
        if (restart == bt_codebomb)
        {
          digitalWrite(LedVerm, LOW);
          CodeMod();
        }
        if (restart == bt_menu)
        {
          digitalWrite(LedVerm, LOW);
          menuPrincipal();
        } //-------------------------------------------------------------------------------------------------------------------------------------------------------------
        while (stop != digitalRead(stopPin) && gamemod == 0)    //Interrupt the counter to open the disarm mode
        {
          noTone(som);
          digitalWrite(LedAma, LOW);
          if (i < 16)
          { i++;
            lcd.clear();
            lcd.setCursor(2, 0);
            lcd.print("Disabling");
            lcd.setCursor(i, 1);
            lcd.print("*");
            delay(800);

            if (i == 16)
            {
              digitalWrite(LedVer, HIGH);
              estado = 0;                          //If the pump is disarmed it changes the verification state
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("--Deactivated--");
              lcd.setCursor(0, 1);
              lcd.print("");
              delay(3000);
              lcd.setCursor(0, 0);
              lcd.print("Restart on/off");      //Reset on and off for next game
              lcd.setCursor(0, 1);
              lcd.print("New=A-- Menu=C--");      //release menu to restart the game or return to the mode menu
              digitalWrite(LedVerm, LOW);       //Ledverm (LedVerm)
              restart = keypad.waitForKey();
            }
          }
          if (restart == bt_timebomb)
          {
            digitalWrite(LedVer, LOW);
            TimeMod();
          }
          if (restart == bt_menu)
          {
            digitalWrite(LedVer, LOW);
            menuPrincipal();
          }
        }
        if (settimeS1 > 47)                     //loop does timer seconds
        {
          lcd.setCursor(0, 0);
          lcd.print("   ");
          lcd.setCursor(13, 0);
          lcd.print("   ");
          lcd.setCursor(0, 1);
          lcd.print("    ");
          lcd.setCursor(12, 1);
          lcd.print("    ");
          lcd.setCursor(0, 0);
          lcd.print("------BOMB------");
          lcd.setCursor(4, 1);
          lcd.print(settimeH0);
          lcd.setCursor(5, 1);
          lcd.print(settimeH1);
          lcd.setCursor(6, 1);
          lcd.print(":");
          lcd.setCursor(7, 1);
          lcd.print(settimeM0);
          lcd.setCursor(8, 1);
          lcd.print(settimeM1);
          lcd.setCursor(9, 1);
          lcd.print(":");
          lcd.setCursor(10, 1);
          lcd.print(settimeS0);
          lcd.setCursor(11, 1);
          lcd.print(settimeS1);
          //lcd.setCursor(11,1);
          //lcd.print(settimeS1);
          noTone(som);
          digitalWrite(LedAma, LOW);
          digitalWrite(LedVerm, LOW); // Synchronization both LED Yellow and Red LED (LedVerm)
          delay(segundo);
          digitalWrite(LedAma, HIGH);
          digitalWrite(LedVerm, HIGH);  //Synchronization both LED Yellow and Red LED (LedVerm)
          tone(som, 1500, 1000);
          settimeS1--;

          if (settimeS1 == 47 && settimeS0 > 48)
          {
            lcd.setCursor(10, 1);
            settimeS0--;
            lcd.print(settimeS0);
            settimeS1 = 57;
            lcd.setCursor(11, 1);
            lcd.print(settimeS1);
          }
          if (settimeS1 == 47 && settimeS0 == 48 && settimeM1 > 48)     //loop does timer minutes
          {
            lcd.setCursor(8, 1);
            settimeM1--;
            lcd.print(settimeM1);
            settimeS0 = 53;
            lcd.setCursor(10, 1);
            lcd.print(settimeS0);
            settimeS1 = 57;
            lcd.setCursor(11, 1);
            lcd.print(settimeS0);
          }
          if (settimeS1 == 47 && settimeS0 == 48 && settimeM1 == 48 && settimeM0 > 48)
          {
            lcd.setCursor(7, 1);
            settimeM0--;
            lcd.print(settimeM0);
            settimeM1 = 57;
            lcd.setCursor(8, 1);
            lcd.print(settimeM1);
            settimeS0 = 53;
            lcd.setCursor(10, 1);
            lcd.print(settimeS0);
            settimeS1 = 57;
            lcd.setCursor(11, 1);
            lcd.print(settimeS1);
          }
          if (settimeS1 == 47 && settimeS0 == 48 && settimeM1 == 48 && settimeM0 == 48 && settimeH1 > 48) //loop does timer hours
          {
            lcd.setCursor(5, 1);
            settimeH1--;
            lcd.print(settimeH1);
            settimeM0 = 53;
            lcd.setCursor(7, 1);
            lcd.print(settimeM0);
            settimeM1 = 57;
            lcd.setCursor(8, 1);
            lcd.print(settimeM1);
            settimeS0 = 53;
            lcd.setCursor(10, 1);
            lcd.print(settimeS0);
            settimeS1 = 57;
            lcd.setCursor(11, 1);
            lcd.print(settimeS1);
          }
          if (settimeS1 == 47 && settimeS0 == 48 && settimeM1 == 48 && settimeM0 == 48 && settimeH1 == 48 && settimeH0 > 48)
          {
            lcd.setCursor(4, 1);
            settimeH0--;
            lcd.print(settimeH0);
            settimeH1 = 57;
            lcd.setCursor(5, 1);
            lcd.print(settimeH1);
            settimeM0 = 53;
            lcd.setCursor(7, 1);
            lcd.print(settimeM0);
            settimeM1 = 57;
            lcd.setCursor(8, 1);
            lcd.print(settimeM1);
            settimeS0 = 53;
            lcd.setCursor(10, 1);
            lcd.print(settimeS0);
            settimeS1 = 57;
            lcd.setCursor(11, 1);
            lcd.print(settimeS1);
          }
          if (settimeS1 == 47 && settimeS0 == 48 && settimeM1 == 48 && settimeM0 == 48 && settimeH1 == 48 && settimeH0 == 48 && gamemod == 1 || segundo == 0)
          { lcd.clear(); digitalWrite(LedAma, LOW); digitalWrite(LedVerm, HIGH); lcd.setCursor(4, 0); lcd.print("BOOM!!!!"); lcd.setCursor(0, 1); lcd.print("New=B  Menu=C"); gamemod = 0; restart = keypad.waitForKey();
            if (restart == bt_codebomb) {
              digitalWrite(LedVerm, LOW);
              CodeMod();
            }
            if (restart == bt_menu) {
              digitalWrite(LedVerm, LOW);
              menuPrincipal();
            }
          }
          if (settimeS1 == 47 && settimeS0 == 48 && settimeM1 == 48 && settimeM0 == 48 && settimeH1 == 48 && settimeH0 == 48 && gamemod == 0)
          { //Check the elapsed time if you have 0 left mark the detonation and release menu       
            digitalWrite(LedAma, LOW);
            digitalWrite(LedVerm, HIGH);
            lcd.clear();
            lcd.setCursor(4, 0);
            lcd.print("BOOM");
            lcd.setCursor(0, 1);
            lcd.print("New=A  Menu=C");
            restart = keypad.waitForKey();
            if (restart == bt_timebomb)
            {
              digitalWrite(LedVerm, LOW);
              TimeMod();
            }
            digitalWrite(LedVerm, LOW);
            if (restart == bt_menu)
            {
              menuPrincipal();
            }
          }
        }
      }
    }

    if (var1 == bt_cancel)          // re-enables the choice of time if you have set the wrong playing time
    {
      lcd.clear();
      lcd.print("Cleared");
      delay(1000);
      TimeMod();
    }
  }
}


// FIM TIME MOD

//CODE MOD

void CodeMod()
{
  char var2;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Set Code");
  lcd.setCursor(8, 0);
  lcd.print("-Clear=#");
  lcd.setCursor(0, 1);
  lcd.print("*****");
  lcd.setCursor(8, 1);
  lcd.print("-Enter=*");
  cod1 = keypad.waitForKey();
  if (cod1 != NO_KEY)
  {
    lcd.setCursor(0, 1);
    lcd.print(cod1);
    cod2 = keypad.waitForKey();
    lcd.setCursor(1, 1);
    lcd.print(cod2);
    cod3 = keypad.waitForKey();
    lcd.setCursor(2, 1);
    lcd.print(cod3);
    cod4 = keypad.waitForKey();
    lcd.setCursor(3, 1);
    lcd.print(cod4);
    cod5 = keypad.waitForKey();
    lcd.setCursor(4, 1);
    lcd.print(cod5);
    var2 = keypad.waitForKey();
    if (var2 == bt_enter)
    {

      TimeMod();
    }
    if (var2 == bt_cancel)
    {
      lcd.clear();
      lcd.print("Cleared");
      delay(1000);
      CodeMod();
    }
  }
}

void AlarmeMod()
{
  int LedVerm = A0;                         //Function set time (Start)
  pinMode(LedVerm, OUTPUT);
  int LedAma = A3;
  pinMode(LedAma, OUTPUT);
  int LedVer = 1;
  pinMode(LedVer, OUTPUT);
  int sensorPin = A5;
  pinMode(sensorPin, INPUT);
  int alarme;
  alarme = digitalRead(sensorPin);
  //digitalWrite(sensor, LOW);

  char al = 1;
  while (al == 1) {
    if (alarme == HIGH)
    {
      digitalWrite(LedVer, HIGH);
      digitalWrite(LedVerm, LOW);
    }
    else
    {
      digitalWrite(LedVerm, HIGH);
      digitalWrite(LedVer, LOW);
    }
  }
}
