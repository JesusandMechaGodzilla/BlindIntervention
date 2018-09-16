#ifndef MAIN_H
#define MAIN_H

#include "Arduino.h"
#include "FlexCAN.h"
#include "ChRt.h"

static FlexCAN CANbus(500000,0);

const int DRIVER_CONTROL_BASE = 0x500;
const int MOTOR_CONTROL_BASE =  0x400;

#endif
