#ifndef led_included
#define led_included

#define LED_RED BIT0
#define LED_GREEN BIT6
#define LEDS (BIT0 | BIT6)

void led_init();
void led_update();
void led_changer();
char toggle_red();
char toggle_green();

extern unsigned char leds_changed;
extern unsigned char green_led_state;
extern unsigned char red_led_state;

#endif
