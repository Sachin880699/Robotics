String inputs;  
#define relay1 2 //connect relay1 to pin 9  
#define relay2 3 //connect relay2 to pin 8  
#define relay3 4 //connect relay3 to pin 7  
#define relay4 5 //connect relay4 to pin 6  
#define relay5 6 //connect relay5 to pin 5  
#define relay6 7 //connect relay6 to pin 4  
#define relay7 8 //connect relay7 to pin 3  
#define relay8 9 //connect relay8 to pin 2  
void setup(){  
  Serial.begin(9600); //set rate for communicating with phone  
  pinMode(relay1, OUTPUT); //set relay1 as an output  
  pinMode(relay2, OUTPUT); //set relay2 as an output  
  pinMode(relay3, OUTPUT); //set relay1 as an output  
  pinMode(relay4, OUTPUT); //set relay2 as an output  
  pinMode(relay5, OUTPUT); //set relay1 as an output  
  pinMode(relay6, OUTPUT); //set relay2 as an output  
  pinMode(relay7, OUTPUT); //set relay1 as an output  
  pinMode(relay8, OUTPUT); //set relay2 as an output  
  digitalWrite(relay1, LOW); //switch relay1 off  
  digitalWrite(relay2, LOW); //switch relay2 off  
  digitalWrite(relay3, LOW); //switch relay1 off  
  digitalWrite(relay4, LOW); //switch relay2 off  
  digitalWrite(relay5, LOW); //switch relay1 off  
  digitalWrite(relay6, LOW); //switch relay2 off  
  digitalWrite(relay7, LOW); //switch relay1 off  
  digitalWrite(relay8, LOW); //switch relay2 off  
}  
void loop(){  
  while(Serial.available()){ //check if there are available bytes to read  
    delay(10); //delay to make it stable  
    char c = Serial.read(); //conduct a serial read  
    if (c == '#'){  
      break; //stop the loop once # is detected after a word  
    }  
    inputs += c; //means inputs = inputs + c  
  }  
  if (inputs.length() >0){  
    Serial.println(inputs);  
    if(inputs == "A"){  
      digitalWrite(relay1, LOW);  
    }  
    else if(inputs == "a"){  
      digitalWrite(relay1, HIGH);  
    }  
    else if(inputs == "B"){  
      digitalWrite(relay2, LOW);  
    }  
    else if(inputs == "b"){  
      digitalWrite(relay2, HIGH);  
    }  
    else if(inputs == "C"){  
      digitalWrite(relay3, LOW);  
    }  
    else if(inputs == "c"){  
      digitalWrite(relay3, HIGH);  
    }  
    else if(inputs == "D"){  
      digitalWrite(relay4, LOW);  
    }  
    else if(inputs == "d"){  
      digitalWrite(relay4, HIGH);  
    }  
    else if(inputs == "E"){  
      digitalWrite(relay5, LOW);  
    }  
    else if(inputs == "e"){  
      digitalWrite(relay5, HIGH);  
    }  
    else if(inputs == "F"){  
      digitalWrite(relay6, LOW);  
    }  
    else if(inputs == "f"){  
      digitalWrite(relay6, HIGH);  
    }  
    else if(inputs == "G"){  
      digitalWrite(relay7, LOW);  
    }  
    else if(inputs == "g"){  
      digitalWrite(relay7, HIGH);  
    }  
    else if(inputs == "H"){  
      digitalWrite(relay8, LOW);  
    }  
    else if(inputs == "h"){  
      digitalWrite(relay8, HIGH);  
    }  
    inputs="";  
  }  
}  
