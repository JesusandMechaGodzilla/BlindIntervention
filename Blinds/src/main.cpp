#include "main.hpp"
#include "ChRt.h"
#include <Arduino.h>

int avgVal;

void mainsetup(){
  readSetup();
  motorSetup();
}


void setup(){
  Serial.begin(9600);
chBegin(mainsetup);


}

void loop(){

}
