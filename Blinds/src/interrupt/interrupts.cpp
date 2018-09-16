#include "interrupts.hpp"
CH_IRQ_HANDLER(temp)
{
    CH_IRQ_PROLOGUE();

        if(temperatureState) temperatureState = 0;
        else temperatureState = 1;

    CH_IRQ_EPILOGUE();
}

CH_IRQ_HANDLER(privacy)
{
    CH_IRQ_PROLOGUE();

    if(privacyState) privacyState = 0;
    else privacyState = 1;

    CH_IRQ_EPILOGUE();
}

CH_IRQ_HANDLER(up)
{
    CH_IRQ_PROLOGUE();

    adjSetting ++;

    CH_IRQ_EPILOGUE();
}

CH_IRQ_HANDLER(down)
{
    CH_IRQ_PROLOGUE();

            adjSetting--;

    CH_IRQ_EPILOGUE();
}

void interruptSetup(){
  pinMode(6, INPUT);
  pinMode(5,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  attachInterrupt(digitalPinToInterrupt(6),up,HIGH);
  attachInterrupt(digitalPinToInterrupt(5),down,HIGH);
  attachInterrupt(digitalPinToInterrupt(7),privacy,HIGH);
  attachInterrupt(digitalPinToInterrupt(8),temp,HIGH);
}
