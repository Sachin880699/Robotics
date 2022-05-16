
int f = 13;
int g = 12;
int e = 11;
int d = 10;
int c = 9;
int b = 8;
int a = 7;  //7 Segment pin

int buttonPin = 5;  //the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status



int p=0;    // variable

void setup() {

  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(a, OUTPUT);

  pinMode(buttonPin, INPUT);
}

void loop()
{
  
   buttonState = digitalRead(buttonPin);
   
   if (buttonState == HIGH)
 
    {
      p++;
      delay(1000);
    } 
    
 if(p==0)
{ 
 digitalWrite(a,1); 
 digitalWrite(b,1);  
 digitalWrite(c,1);  
 digitalWrite(d,1);  
 digitalWrite(e,1);  
 digitalWrite(f,1);  
 digitalWrite(g,0);   // 0
}
 
  if(p==1)
  {
 digitalWrite(a,0); 
 digitalWrite(b,1);  
 digitalWrite(c,1);  
 digitalWrite(d,0);  
 digitalWrite(e,0);  
 digitalWrite(f,0);  
 digitalWrite(g,0);   // 1
  }

  if(p==2)
 { 
 digitalWrite(a,1); 
 digitalWrite(b,1);  
 digitalWrite(c,0);  
 digitalWrite(d,1);  
 digitalWrite(e,1);  
 digitalWrite(f,0);  
 digitalWrite(g,1);   // 2
 }
  if(p==3)
  {
 digitalWrite(a,1); 
 digitalWrite(b,1);  
 digitalWrite(c,1);  
 digitalWrite(d,1);  
 digitalWrite(e,0);  
 digitalWrite(f,0);  
 digitalWrite(g,1);   // 3
  } 
 
  if(p==4)
  {
  digitalWrite(a,0); 
 digitalWrite(b,1);  
 digitalWrite(c,1);  
 digitalWrite(d,0);  
 digitalWrite(e,0);  
 digitalWrite(f,1);  
 digitalWrite(g,1);   // 4
  }   

 if(p==5)
 {
 digitalWrite(a,1); 
 digitalWrite(b,0);  
 digitalWrite(c,1);  
 digitalWrite(d,1);  
 digitalWrite(e,0);  
 digitalWrite(f,1);  
 digitalWrite(g,1);   // 5
 }
  
   if(p==6)
   {
   digitalWrite(a,0); 
 digitalWrite(b,0);  
 digitalWrite(c,1);  
 digitalWrite(d,1);  
 digitalWrite(e,1);  
 digitalWrite(f,1);  
 digitalWrite(g,1);   // 6
   }
  if(p==7)
  {
  digitalWrite(a,1); 
 digitalWrite(b,1);  
 digitalWrite(c,1);  
 digitalWrite(d,0);  
 digitalWrite(e,0);  
 digitalWrite(f,0);  
 digitalWrite(g,0);   // 7
  }  
 
  if(p==8)
  {
 digitalWrite(a,1); 
 digitalWrite(b,1);  
 digitalWrite(c,1);  
 digitalWrite(d,1);  
 digitalWrite(e,1);  
 digitalWrite(f,1);  
 digitalWrite(g,1);   // 8
  } 
 
  if(p==9)
{
  digitalWrite(a,1); 
 digitalWrite(b,1);  
 digitalWrite(c,1);  
 digitalWrite(d,0);  
 digitalWrite(e,0);  
 digitalWrite(f,1);  
 digitalWrite(g,1);   // 9
} 

if(p==10)
{
  p=0;
}
             
}
