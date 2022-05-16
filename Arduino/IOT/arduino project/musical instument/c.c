#define c 262
#define d 294
#define e 330
#define f 349


int peizoPin = 8;
int button1 = 7;
int button2 = 2;
int button3 = 12;
int button4 = 4;

  
void setup() 
{
  Serial.begin(9600);
  pinMode(peizoPin, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);

}
void loop() 
{
  int button1Value = digitalRead(button1);
  
  int button2Value = digitalRead(button2);
  
  int button3Value = digitalRead(button3);
  
  int button4Value = digitalRead(button4);
  
  
  
  
  
  delay(50);
  
  if(button1Value == 1) 
  {
    tone(peizoPin, c);
  }
  else if(button2Value == 1) 
  {
    tone(peizoPin, d);
  }
  else if(button3Value == 1) 
  {
    tone(peizoPin, e);
  }
  else if(button4Value == 1) 
  {
    tone(peizoPin, f);
  }
  
  else 
  {
    noTone(peizoPin);
  }
}


