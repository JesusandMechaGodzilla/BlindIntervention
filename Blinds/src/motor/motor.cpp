#include "motor.hpp"
#include "Servo.h"
#include "ChRt.h"
static THD_WORKING_AREA(wa_motor_thread, 256);
static THD_FUNCTION(motor_thread, arg) {
(void) arg;
systime_t time = chVTGetSystemTimeX();
Servo myServo;
myServo.attach(2);
//ServoPosition 0 is the position when the blinds are as closed down, whereas ServoPosition 180 is closed above
int servoPosition = 90;

while(true){
  Serial.println("Current Servo Position: ");
  Serial.print(servoPosition);
  time += MS2ST(2000);
  //avgVal is the indoor
  //adjSetting is the effective user setting
  if(timeDay){
    int increment = (adjSetting - avgVal)/10;
    if(increment>4)
      increment = 4;
    if(servoPosition<90 && servoPosition >= 0){
      servoPosition += increment;
      if(servoPosition <0)
        servoPosition = 0;
      }
    else{
      servoPosition -= increment;
      if(servoPosition>180)
        servoPosition = 180;
      }
  }
  else
    servoPosition = 0;

  myServo.write(servoPosition);


   chThdSleepUntil(time);
}

}

void motorSetup(){
  chThdCreateStatic(wa_motor_thread, sizeof(wa_motor_thread),
      NORMALPRIO, motor_thread, NULL);
}
