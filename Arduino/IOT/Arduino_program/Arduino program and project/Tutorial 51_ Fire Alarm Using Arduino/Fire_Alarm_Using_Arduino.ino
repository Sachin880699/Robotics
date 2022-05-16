
int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
int sensorValue = 0;        // value read from the pot

int buzz = 13;


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(buzz, OUTPUT);

}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  



Serial.print("sensor = ");
Serial.println(sensorValue);


  delay(500);
  
  if(sensorValue<900)
  {
    digitalWrite(buzz,1);

  }
  else
  {
    digitalWrite(buzz,0);
  }
  
  
  
  
}

