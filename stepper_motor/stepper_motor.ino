#include <Stepper.h>

const int stepsPerRevolution = 200;
//stepper(steps, coil1, coil1, coil2, coil2); 
Stepper stepper(stepsPerRevolution, 5, 9, 6, 10);

void setup() {
  stepper.setSpeed(60);
  Serial.begin(9600);
}

void loop() {
  stepper.step(stepsPerRevolution);
}