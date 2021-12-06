#include <msp430.h>
#include "led.h"
#include "switches.h"

char switch_state_change, switch1_statedown, switch2_statedown, switch3_statedown;

void led_init(){
  P1DIR |= LEDS;
  switch_state_changed = 1;
  led_update();
}

void led_update(){
  char ledFlags = 0;
  
  if(switch_state_changed && state == 1)
    {
      ledFlags |= switch1_statedown ? LED_GREEN: 0;
      ledFlags |= switch1_statedown ? 0: LED_RED;

      P1OUT &= (0xff - LEDS) | ledFlags;
      P1OUT |= ledFlags;
      
    }

  if(switch_state_changed && state == 2){
    ledFlags |= switch2_statedown ? LED_RED: 0;
    ledFlags |= switch2_statedown ? 0: LED_GREEN;
    P1OUT &= (0xff - LEDS) | ledFlags;
    P1OUT |= ledFlags;
  }

  if(switch_state_changed && state == 3){
    P1OUT |= LED_GREEN;
    P1OUT |= LED_RED;
  }
  

  

  switch_state_changed = 0;

}

void led_changer(){
  char changed = 0;

  static enum {R=0, G=1} color = G;
  switch(color){

  case R: changed = toggle_red(); color = G;
    break;
  case G: changed = toggle_green(); color = R;break; 
  }
  
}

char toggle_red(){
  static char state = 0;

  switch(state)
    {
    case 0:
      green_led_state = 1;
      state = 1;
      break;

    case 1:
      red_led_state = 0;
      state = 0;
      break;
    }
  return 1;
  
}

char toggle_green(){
  char changed = 0;
  if(red_led_state == 1){
    green_led_state^= 1;
    changed = 1;
  }
  return changed;
}

