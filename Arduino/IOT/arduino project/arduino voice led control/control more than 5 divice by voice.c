String voice;
int RED = 2;
int GREEN = 3;
int BLUE = 4;
int BLACK = 5;
int ORANGE = 6;

void RedOn(){
digitalWrite (RED, HIGH);
}
void RedOff(){
digitalWrite (RED, LOW);
}
void GreenOn(){
digitalWrite (GREEN, HIGH);
}
void GreenOff(){
digitalWrite (GREEN, LOW);
}
void BlueOn(){
digitalWrite (BLUE, HIGH);
}
void BlueOff(){
digitalWrite (BLUE, LOW);
}

void BlackOn(){
digitalWrite (BLACK, HIGH);
}
void BlackOff(){
digitalWrite (BLACK, LOW);
}

void OrangeOn(){
digitalWrite (ORANGE, HIGH);
}
void OrangeOff(){
digitalWrite (ORANGE, LOW);
}



void allon() {
digitalWrite (RED, HIGH);
digitalWrite (GREEN, HIGH);
digitalWrite (BLUE, HIGH);
digitalWrite (BLACK,HIGH);
digitalWrite (ORANGE, HIGH);
}
void alloff() {
digitalWrite (RED, LOW);
digitalWrite (GREEN, LOW);
digitalWrite (BLUE, LOW);
digitalWrite (BLACK, LOW);
digitalWrite (ORANGE, LOW);

}
void setup() {
Serial.begin(9600);
pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(BLUE, OUTPUT);
pinMode(BLACK, OUTPUT);
pinMode(ORANGE, OUTPUT);
}
void loop() {
while(Serial.available()) {
delay(10);
char c=Serial.read();
if(c=='#')
{break; }
voice += c;
}
if (voice.length() > 0) {
Serial.println(voice);
if (voice == "on" || voice == "all")
{
allon() ;
}
else if (voice == "off" || voice=="all off")
{
alloff() ;
}
else if(voice =="red" || voice =="red on"){
RedOn();
}
else if(voice =="red off"){
RedOff();
}
else if(voice =="green" || voice =="green on"){
GreenOn();
}
else if( voice =="green off" ){
GreenOff();
}
else if(voice =="blue" || voice =="blue on"){
BlueOn();
}
else if(voice =="red" || voice =="red on"){
BlackOn();
}
else if(voice =="red off"){
BlackOff();
}
else if(voice =="orange" || voice =="orange on"){
BlackOn();
}
else if(voice =="orange off"){
BlackOff();
}



else if(voice =="blue off"){
BlueOff();
}
voice="";
}
}
