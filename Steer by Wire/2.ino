#include <AccelStepper.h>
#define stepPin 10
#define dirPin 9
String inputString;
float angle;
AccelStepper stepper(1,stepPin,dirPin);

void setup() { 
  stepper.setMaxSpeed(1100); //1100 step/sec =330rpm will give a torque ~13-14Nm
  stepper.setAcceleration(9333);
}

void loop() {
  
  while (Serial.available())
  {
    inputString=Serial.readString();
    angle = inputString.toFloat();
    Serial.println(angle);
  }
  
  stepper.move(angle); //will rotate to the 'angle' relative to current position
  stepper.run();  
}
