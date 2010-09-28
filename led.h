#ifndef LED_H_INCLUDED
#define LED_H_INCLUDED

#define LED1	0
#define LED2	1

void led_init(void);
void led_on(int led_no);
void led_off(int led_no);

#endif /* LED_H_INCLUDED */
