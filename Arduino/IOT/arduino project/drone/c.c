/* Remote Controller */
#include <SoftwareSerial.h>

/* I/O Port Assignment */
#define THROTTLE_PIN 	A5

#define ARM_PIN 		2
#define YAW_CCW_PIN 	3
#define YAW_CW_PIN		4

#define PITCH_FW_PIN 	6
#define PITCH_BW_PIN 	5

#define ROLL_LEFT_PIN	8
#define ROLL_RIGHT_PIN	7

#define ARM_LED_PIN		13

//#define SERIAL_DEBUG_MODE

SoftwareSerial mySerial(11,12);//rx, tx

int valAltitude;
unsigned char flgArmStatus = 0;
unsigned char txPacketBuf[9];

typedef struct {
  byte Pfw 	: 1;
  byte Pbw 	: 1;
  byte Rl  	: 1;
  byte Rr  	: 1;
  byte Yccw : 1;
  byte Ycw 	: 1;
} btnPRYstatus;

btnPRYstatus	PRY = {0, 0, 0, 0, 0, 0, };

void fncGetThrottleData(void);
void fncGetYawData(void);
void fncGetPitchData(void);
void fncGetRollData(void);

void fncCmdTxHandler(void);

// the setup routine runs once when you press reset:
void setup() {
  	#if SERIAL_DEBUG_MODE
  		Serial.begin(9600);
  	#endif
  
  	mySerial.begin(2400);
  	pinMode(ARM_LED_PIN, OUTPUT);
  
  	*(txPacketBuf + 0) = '$';
  	*(txPacketBuf + 8) = 'E';
  
  	while(!flgArmStatus)	{
        flgArmStatus = digitalRead(ARM_PIN);
        digitalWrite(13, digitalRead(ARM_PIN));
    }
  	mySerial.write('A');
}

// the loop routine runs over and over again forever:
void loop() {
    if(flgArmStatus)  {
        fncGetThrottleData();
        fncGetYawData();
        fncGetPitchData();
        fncGetRollData();

        fncCmdTxHandler();

        flgArmStatus = digitalRead(ARM_PIN);
        digitalWrite(13, digitalRead(ARM_PIN));

        if(!flgArmStatus) mySerial.write('D');

        delay(100);
    }
}

void fncGetThrottleData(void)	{
    valAltitude = analogRead(THROTTLE_PIN);
    valAltitude /= 4;
  	*(txPacketBuf + 1) = valAltitude;
}

void fncGetYawData(void)	{
  	PRY.Yccw = digitalRead(YAW_CCW_PIN);
  	*(txPacketBuf + 2) = PRY.Yccw;
	PRY.Ycw = digitalRead(YAW_CW_PIN);
  	*(txPacketBuf + 3) = PRY.Ycw;
}

void fncGetPitchData(void)	{
	PRY.Pfw = digitalRead(PITCH_FW_PIN);
  	*(txPacketBuf + 4) = PRY.Pfw;
	PRY.Pbw = digitalRead(PITCH_BW_PIN);
  	*(txPacketBuf + 5) = PRY.Pbw;
}

void fncGetRollData(void)	{
	PRY.Rl = digitalRead(ROLL_LEFT_PIN);
  	*(txPacketBuf + 6) = PRY.Rl;
	PRY.Rr = digitalRead(ROLL_RIGHT_PIN);
  	*(txPacketBuf + 7) = PRY.Rr;
}

void fncCmdTxHandler(void)	{
    for(unsigned char index = 0; index <= 8; index++)	{
        mySerial.write(*(txPacketBuf+index));
        #if SERIAL_DEBUG_MODE
            Serial.print(*(txPacketBuf+index));
        #endif
    }
    #if SERIAL_DEBUG_MODE
      	Serial.println("E");
    #endif
}
