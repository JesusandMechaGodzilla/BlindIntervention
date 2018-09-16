#include "read.hpp"
#include "ChRt.h"
#include "TM1637.h"
#define CLK 0
#define DIO 1
TM1637 tm1637(CLK, DIO);

static THD_WORKING_AREA(wa_read_thread, 256);

static THD_FUNCTION(read_thread, arg) {
(void) arg;

tm1637.init();
tm1637.set(BRIGHT_TYPICAL);

tm1637.display(0,0);
tm1637.display(1,adjSetting/100);
tm1637.display(2,((adjSetting/10)%10));
tm1637.display(3,(adjSetting%10));


systime_t time = chVTGetSystemTimeX();
int reading = 0;
for (int i = 0;i < 60; i++) {
  reading = analogRead(A0);
  avgArray[i] = reading;
}


while(true){
  time += MS2ST(1000);


  reading = analogRead(A0);
  avgVal = 0;
  for (int i = 0; i < 59; i++) {
    avgArray[i] = avgArray[i + 1];
    avgVal += avgArray[i+1];
  }
  avgArray[59] = reading;
  avgVal += reading;
  avgVal = avgVal/120;
  if (avgVal > 100) avgVal = 100;
  Serial.println("average");
    Serial.println(avgVal);
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
