#include "libTimer.h"
#include "buzzer.h"
#include <msp430.h>

void buzzer_init()
{
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

void buzzer_set_period(short cycles)
{
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}

void off()
{
  CCR0 = 0;
  CCR1 = 0;
}

void happy_birthday(){
  float a = 880.0;
  float b = 987.8;
  float c = 523.3;
  float d = 587.3;
  float e = 659.3;
  float f = 698.5;
  float g = 784.0;

  float notes[27] = {c,c,d,c,f,e,0,c,c,d,c,g,f,0,c,c,c,a,b,g,0,a,a,b,f,g,f};
  for(int i = 0; i < 27; i++){
    buzzer_set_period(notes[i]);
    __delay_cycles(10000);
   
  }
  buzzer_set_period(0);
}

