#include "sw.h"

/* 
 * SW1		CN3-3	P4-4
 * SW2		CN3-4	P4-5
 * SW3		CN3-5	P4-6
 * SW4		CN3-6	P4-7
 * SW5_1	CN3-23	P2-0
 * SW5_2	CN3-24	P2-1
 * SW5_3	CN3-25	P2-2
 * SW5_4	CN3-26	P2-3
 * SW5_5	CN3-27	P2-4
 * SW5_6	CN3-28	P2-5
 * SW5_7	CN3-29	P2-6
 * SW5_8	CN3-30	P2-7
 */

#define P2DDR	((volatile unsigned char *) 0xFFFFC1)
#define P2DR	((volatile unsigned char *) 0xFFFFC3)
#define P2PCR	((volatile unsigned char *) 0xFFFFD8)

#define P4DDR	((volatile unsigned char *) 0xFFFFC5)
#define P4DR	((volatile unsigned char *) 0xFFFFC7)
#define P4PCR	((volatile unsigned char *) 0xFFFFDA)

void sw_init(void)
{
	*P4DDR = 0x00; /* ポート4を入力に設定 */
	*P4PCR |= 0xF0; /* P4-4～7のプルアップON */

	*P2DDR = 0x00; /* ポート2を入力に設定 */
	*P2PCR = 0xFF; /* P2-0～7のプルアップON */
}

int sw_is_on(int sw_no)
{
	switch (sw_no) {
	case SW1:
		return (*P4DR & 0x10) ? 0 : 1;
	case SW2:
		return (*P4DR & 0x20) ? 0 : 1;
	case SW3:
		return (*P4DR & 0x40) ? 0 : 1;
	case SW4:
		return (*P4DR & 0x80) ? 0 : 1;
	case SW5_1:
		return (*P2DR & 0x01) ? 0 : 1;
	case SW5_2:
		return (*P2DR & 0x02) ? 0 : 1;
	case SW5_3:
		return (*P2DR & 0x04) ? 0 : 1;
	case SW5_4:
		return (*P2DR & 0x08) ? 0 : 1;
	case SW5_5:
		return (*P2DR & 0x10) ? 0 : 1;
	case SW5_6:
		return (*P2DR & 0x20) ? 0 : 1;
	case SW5_7:
		return (*P2DR & 0x40) ? 0 : 1;
	case SW5_8:
		return (*P2DR & 0x80) ? 0 : 1;
	}
	return 0;
}

