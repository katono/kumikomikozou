#ifndef SW_H_INCLUDED
#define SW_H_INCLUDED

#define SW1		0
#define SW2		1
#define SW3		2
#define SW4		3
#define SW5_1	4
#define SW5_2	5
#define SW5_3	6
#define SW5_4	7
#define SW5_5	8
#define SW5_6	9
#define SW5_7	10
#define SW5_8	11


void sw_init(void);
int sw_is_on(int sw_no);

#endif /* SW_H_INCLUDED */
