#!/usr/bin/python
#----------------------------http://www.lesmartomation.com/clap-to-turn-on-off-lights-using-arduino/



int SOUND_INPUT=4;
int RELAY_OUTPUT=5;
boolean ch_flag=false;
void setup() {

  Serial.begin(9600);
  pinMode(RELAY_OUTPUT, OUTPUT);//Digital input
  pinMode(SOUND_INPUT, INPUT); //Digital output
}

void loop() {
if (digitalRead(SOUND_INPUT)==1){
    ch_flag=!ch_flag;
    digitalWrite(RELAY_OUTPUT,ch_flag);
    Serial.print(ch_flag);
    delay(500);
  }
}
