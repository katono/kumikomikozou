#include "led.h"

#define P5DDR	((volatile unsigned char *) 0xFFFFC8)
#define P5DR	((volatile unsigned char *) 0xFFFFCA)
#define P5PCR	((volatile unsigned char *) 0xFFFFDB)

/* 
 * LED1はP5-0
 * LED2はP5-1
 */


void led_init(void)
{
	*P5DDR = 0xFF; /* ポートを出力に設定 */
}

void led_on(int led_no)
{
	if (led_no == LED1) {
		*P5DR |= 0x01;
	} else if (led_no == LED2) {
		*P5DR |= 0x02;
	}
}

void led_off(int led_no)
{
	if (led_no == LED1) {
		*P5DR &= ~0x01;
	} else if (led_no == LED2) {
		*P5DR &= ~0x02;
	}
}

