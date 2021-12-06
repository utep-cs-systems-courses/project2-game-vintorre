#include <msp430.h>
#include "state_manager.h"
#include "led.h"

void __interrupt_vec(WDT_VECTOR) WDT(){
  static char blink_count = 0;
  states();
  if(++blink_count == 100){
    led_changer();
    blink_count = 0;
  }

  timeAdvStateMachines();
}
