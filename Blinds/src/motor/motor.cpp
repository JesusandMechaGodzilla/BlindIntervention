#include "motor.h"
static THD_WORKING_AREA(wa_motor_thread, 256);
static THD_FUNCTION(motor_thread, arg) {
(void) arg;
systime_t time = chVTGetSystemTimeX();


while(true){
time += MS2ST(1000);
//code here






 chThdSleepUntil(time);
}

  }

void motorSetup(){
  chThdCreateStatic(wa_motor_thread, sizeof(wa_motor_thread),
      NORMALPRIO, motor_thread, NULL);
}
