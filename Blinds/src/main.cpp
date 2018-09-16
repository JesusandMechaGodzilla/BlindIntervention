#include "main.hpp"
#include "ChRt.h"
#include <Arduino.h>


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
