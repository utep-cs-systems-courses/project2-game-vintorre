#include <msp430.h>
#include "switches.h"
#include "state_manager.h"

char state;
char switch_state_down;
char switch_state_change;


static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}

void switch_init()
{
  P2REN |= SWITCHES;
  P2IE |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
  switch_interrupt_handler();
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  if(p2val & SW1 ? 0 : 1){
    states(1);
  }

  else if(p2val & SW2 ? 0 : 1){
    states(2);
  }

  else if(p2val & SW3 ? 0 : 1){
    states(3);
  }

  else if(p2val & SW4 ? 0 : 1){
    states(4);
  }
}
