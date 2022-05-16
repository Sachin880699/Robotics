const byte LED1[]={8,9,10,11,12,13 };
const int P1=2;
const int debaunceDelay=100;
byte stato=1;  


void setup() {
  pinMode(LED1[0], OUTPUT);
  pinMode(LED1[1], OUTPUT);
  pinMode(LED1[2], OUTPUT);
  pinMode(LED1[3], OUTPUT);
  pinMode(LED1[4], OUTPUT);
  pinMode(LED1[5], OUTPUT);
  pinMode(P1, INPUT);
}

void loop() {

  if(digitalRead(P1))

  {

    if(stato<7) stato=stato+1;

    else stato=1;

  }
     
switch(stato)
{ case 1: 
    digitalWrite(LED1[0],LOW);
    digitalWrite(LED1[1],LOW);
    digitalWrite(LED1[2],LOW);
    digitalWrite(LED1[3],LOW);
 	digitalWrite(LED1[4],LOW);
 	digitalWrite(LED1[5],LOW);
    break;
  case 2: 
    digitalWrite(LED1[0],HIGH);
    digitalWrite(LED1[1],LOW);
    digitalWrite(LED1[2],LOW);
    digitalWrite(LED1[3],LOW);
 	digitalWrite(LED1[4],LOW);
 	digitalWrite(LED1[5],LOW);
    break;
  case 3: 
    digitalWrite(LED1[0],LOW);
    digitalWrite(LED1[1],HIGH);
    digitalWrite(LED1[2],LOW);
    digitalWrite(LED1[3],LOW);
 	digitalWrite(LED1[4],LOW);
 	digitalWrite(LED1[5],LOW);
    break;
  case 4: 
    digitalWrite(LED1[0],LOW);
    digitalWrite(LED1[1],LOW);
    digitalWrite(LED1[2],HIGH);
    digitalWrite(LED1[3],LOW);
 	digitalWrite(LED1[4],LOW);
 	digitalWrite(LED1[5],LOW);
    break;
  case 5: 
    digitalWrite(LED1[0],LOW);
    digitalWrite(LED1[1],LOW);
    digitalWrite(LED1[2],LOW);
    digitalWrite(LED1[3],HIGH);
 	digitalWrite(LED1[4],LOW);
 	digitalWrite(LED1[5],LOW);
    break;
 case 6: 
    digitalWrite(LED1[0],LOW);
    digitalWrite(LED1[1],LOW);
    digitalWrite(LED1[2],LOW);
    digitalWrite(LED1[3],LOW);
 	digitalWrite(LED1[4],HIGH);
 	digitalWrite(LED1[5],LOW);
    break;
 case 7: 
    digitalWrite(LED1[0],LOW);
    digitalWrite(LED1[1],LOW);
    digitalWrite(LED1[2],LOW);
    digitalWrite(LED1[3],LOW);
 	digitalWrite(LED1[4],LOW);
 	digitalWrite(LED1[5],HIGH);
    break;
}  

  while (digitalRead(P1) == LOW)
  {
    delay(10);
  }

  delay(debaunceDelay);

}

