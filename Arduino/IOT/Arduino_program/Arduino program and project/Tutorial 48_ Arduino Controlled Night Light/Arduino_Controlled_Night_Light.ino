
int analogInPin = A5;  // Analog input pin that the potentiometer is attached to

int nightlight =13;
int sensorValue = 0;        // value read from the pot


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(nightlight, OUTPUT);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);


  Serial.print("sensor = " );
  Serial.println(sensorValue);

  delay(200);

  if(sensorValue>500)
  {
    digitalWrite(nightlight,1);
    
  }
  else
  {
    digitalWrite(nightlight,0);
  }
 
}
