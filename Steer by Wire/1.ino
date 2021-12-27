#define STEPIN 12
#define DIRIN 11
#define ENBIN 10
String inputString; //input from RPi
float angle;        //store howmuch angle to be turned
// int x;


void setup()
{
  Serial.begin(9600);
  pinMode(STEPIN,OUTPUT);
  pinMode(DIRIN,OUTPUT);
//  pinMode(ENBIN,OUTPUT);
  digitalWrite(ENBIN,HIGH); //active low
}



//assume maximum microstepping for precise control
//pulse/rev =200
//angle turned per pulse = 360/200 = 1.8degree
//no of pulses to turn by x degree = x/1.8

void turnCW(float angle){
    int numPulses = 2*angle*(1/1.8);
    digitalWrite(DIRIN,HIGH);
  
  for (int i =0;i<numPulses;i++){
    digitalWrite(STEPIN,HIGH);
//    Serial.print(1);
    delay(4);
    digitalWrite(STEPIN,LOW);
//    Serial.print(0);
    delay(4);
    while (Serial.available()){
      i=numPulses;}
  }
}


void turnCCW(float angle){
    int numPulses = 2*(1/1.8)*angle;
    digitalWrite(DIRIN,LOW);
  
  for (int i =0;i<numPulses;i++){
    digitalWrite(STEPIN,HIGH);
    delay(4);
    digitalWrite(STEPIN,LOW);
    delay(4);
    while (Serial.available()){
      i=numPulses;}
  }
}



void loop()
{ 
  while(!Serial.available()){}
  while (Serial.available()){
  inputString=Serial.readString();
  angle = inputString.toFloat();
  Serial.println(angle);
  }
  
  
  if (angle>=0){
  turnCW(angle);
  angle=0;
  }
  
  
  if (angle<0){
  turnCCW(-angle);
  angle=0;
  }
}
