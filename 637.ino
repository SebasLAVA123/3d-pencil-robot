#include <AccelStepper.h>
#define MOTOR_INTERFACE_TYPE AccelStepper::HALF4WIRE
#include "Servo.h"
AccelStepper myStepper(MOTOR_INTERFACE_TYPE, 6, 8, 7, 9);
AccelStepper myStepper1(MOTOR_INTERFACE_TYPE, 2, 4, 3, 5);
AccelStepper myStepper2(MOTOR_INTERFACE_TYPE, 10, 12, 11, 13);
Servo miServo;
const int servo = A0;
unsigned long startMillis;
const unsigned long interval = 80000;  
void setup() {
  
  miServo.attach(servo); 

  startMillis = millis();
  
  myStepper.setMaxSpeed(-600);
  myStepper.setSpeed(-600);

  myStepper1.setMaxSpeed(1000);
  myStepper1.setSpeed(-1000);

  //myStepper2.setMaxSpeed(1000);
  //myStepper2.setSpeed(1000);

  miServo.write(90);
  
}
void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - startMillis < interval) {
    
    myStepper.runSpeed();
    myStepper1.runSpeed();
    //myStepper2.runSpeed();
    miServo.write(40);

  } 
  else {
    
    currentMillis = 0;
    myStepper.setSpeed(0);
    myStepper1.setSpeed(0);
    //myStepper2.setSpeed(1000);
    miServo.write(150);
  }
}

