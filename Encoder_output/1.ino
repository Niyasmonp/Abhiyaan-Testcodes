#define enc_chA 2
#define enc_chB 3
volatile int encoder_count =0;

void setup() {
  Serial.begin(19200);
  pinMode(enc_chA,INPUT);
  pinMode(enc_chB,INPUT);
  attachInterrupt(digitalPinToInterrupt(enc_chA),count,RISING);
}

void loop() {
  Serial.write("Encoder Value: ");
  Serial.println(encoder_count);
}

void count(){
  encoder_count ++;
  }
