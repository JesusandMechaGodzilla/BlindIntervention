#include "read.h"
static THD_WORKING_AREA(wa_read_thread, 256);
static THD_FUNCTION(read_thread, arg) {
(void) arg;

systime_t time = chVTGetSystemTimeX();
int reading = 0;
for (int i = 0;i < 60; i++) {
  reading = analogRead(A0);
  avgArray[i] = reading;
}


while(true){
  reading = analogRead(A0);
  avgVal = 0;
  for (int i = 0; i < 59; i++) {
    avgArray[i] = avgArray[i + 1];
    avgVal += avgArray[i+1];
  }
  avgArray[59] = reading;
  avgVal += reading;
  avgVal = avgVal / 60;
//code here
reading = analogRead(A1);
if (reading > day) timeDay = true;
else timeDay = false;
/*
if (temperatureState) {
  reading = analogRead(A2);
  if (reading >= normalTemp + 5){
    adjSetting = adjSetting - (reading - normalTemp);
}
  else if (reading <= normalTemp - 5){
    adjSetting = adjSetting + (normalTemp - reading);
}
*/

 chThdSleepUntil(time);
}










}

void readSetup(){
  chThdCreateStatic(wa_read_thread, sizeof(wa_read_thread),
      NORMALPRIO, read_thread, NULL);
}
