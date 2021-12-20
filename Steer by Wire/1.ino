#define STEPIN 12
#define DIRIN 11
#define ENBIN 10
String inputString; //input from RPi
float angle;        //store howmuch angle to be turned



void setup()
{
  Serial.begin(9600);
  pinMode(STEPIN,OUTPUT);
  pinMode(DIRIN,OUTPUT);
  pinMode(ENBIN,OUTPUT);
  digitalWrite(ENBIN,LOW); //active low
}



//assume maximum microstepping for precise control
//pulse/rev =25000
//angle turned per pulse = 360/25000 =0.0144 degree
//no of pulses to turn by x degree = x/0.0144=69.4444*x


void turnCW(float angle){
  	int numPulses = 69.4444*angle;
    digitalWrite(DIRIN,HIGH);
  
  for (int i =0;i<numPulses;i++){
    digitalWrite(STEPIN,HIGH);
    delayMicroseconds(100);
    digitalWrite(STEPIN,LOW);
    delayMicroseconds(100);

  }
}


void turnCCW(float angle){
  	int numPulses = 69.4444*angle;
    digitalWrite(DIRIN,LOW);
  
  for (int i =0;i<numPulses;i++){
    digitalWrite(STEPIN,HIGH);
    delayMicroseconds(100);
    digitalWrite(STEPIN,LOW);
    delayMicroseconds(100);
  }
}



void loop()
{	
  while (Serial.available()){
  inputString=Serial.readString();
  angle = inputString.toFloat();
  Serial.println(angle);
  }
  
  
  if (angle>=0){
  turnCW(angle);
  }
  
  
  if (angle<0){
  turnCCW(-angle);
  }
}
