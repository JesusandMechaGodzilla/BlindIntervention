#include "main.hpp"
#include "ChRt.h"
#include <Arduino.h>

int avgVal;
int adjSetting = 50;
float temperatureState = 0, privacyState = 0;

void mainsetup(){
  readSetup();
  motorSetup();
}


void setup(){
  interruptSetup();
  Serial.begin(9600);
chBegin(mainsetup);


}

void loop(){

}
