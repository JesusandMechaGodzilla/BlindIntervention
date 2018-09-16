#include "main.hpp"
#include "ChRt.h"
#include <Arduino.h>

int avgVal, adjSetting;
int avgVal;
int adjSetting = 50;
float temperatureState = 0, privacyState = 0;

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
