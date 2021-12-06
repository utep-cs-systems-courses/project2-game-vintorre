#include <msp430.h>
#include "state_manager.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"


void states(int state)
{
  switch(state){
  case 1:
    happy_birthday();
    break;

  case 2:
    off();
    break;
    
  case 3:
    break;

  case 4:
    song();
    break;
  }
  

  led_update();
    
}

static int blinkLimit = 3;

void updateBlinking(){
  static int count = 0;
  count++;
  if(count >= blinkLimit){
    count = 0;
    greenOn(1);
    
  }
  else greenOn(0);
}

void updateTime(){
  static int count = 0;
  if(count >= 250){
    count = 0;
    blinkLimit++;
    if(blinkLimit >= 8)
      blinkLimit = 0;
  }
}

void timeAdvStateMachine(){
  updateBlinking();
  updateTime();
}
