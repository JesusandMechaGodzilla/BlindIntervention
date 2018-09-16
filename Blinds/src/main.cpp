#include "main.hpp"
#include "ChRt.h"
#include <Arduino.h>

int avgVal, adjSetting;

void mainsetup(){
  adjSetting = 50;
  readSetup();
  motorSetup();
}


void setup(){
  Serial.begin(9600);
chBegin(mainsetup);


}

void loop(){

}
