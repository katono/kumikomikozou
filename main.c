#include "defines.h"
#include "serial.h"
/*#include "sci.h"*/
#include "led.h"
#include "sw.h"
#include "lib.h"
#include <cstl/vector.h>
#include <cstl/list.h>
#include "Pool.h"

#define INTR_ENABLE		asm volatile ("andc.b #0x3f,ccr")
#define INTR_DISABLE	asm volatile ("orc.b  #0xc0,ccr")

int global_data = 0x10;
int global_bss;
static int static_data = 0x20;
static int static_bss;

static void printval(void)
{
	puts("global_data : "); putxval(global_data, 0); puts("\n");
	puts("global_bss  : "); putxval(global_bss,  0); puts("\n");
	puts("static_data : "); putxval(static_data, 0); puts("\n");
	puts("static_bss  : "); putxval(static_bss,  0); puts("\n");
}

Pool pool;
int pool_buf[0x800 / sizeof(int)];
#define malloc(s)      Pool_malloc(&pool, s)
#define realloc(p, s)  Pool_realloc(&pool, p, s)
#define free(p)        Pool_free(&pool, p)

/*CSTL_LIST_INTERFACE(IntList, int)*/
/*CSTL_LIST_IMPLEMENT(IntList, int)*/

/*CSTL_VECTOR_INTERFACE(IntVector, int)*/
/*CSTL_VECTOR_IMPLEMENT(IntVector, int)*/

static int init(void)
{
	extern int erodata, data_start, edata, bss_start, ebss;
	memcpy(&data_start, &erodata, (size_t)&edata - (size_t)&data_start);
	memset(&bss_start, 0, (size_t)&ebss - (size_t)&bss_start);

	led_init();
	sw_init();
	serial_init(SERIAL_DEFAULT_DEVICE);
/*    sci_init(SCIDEV1, 9600, 8, PARITY_NON, 1);*/
	Pool_init(&pool, pool_buf, sizeof pool_buf, sizeof pool_buf[0]);
}

void cmd_map(void);

int main(void)
{
/*    int c = 0;*/
/*    int i = 0;*/
/*    int data = 0;*/
/*    IntVector *vec;*/
/*    IntList *lst;*/
/*    INTR_DISABLE;*/
	init();
/*    INTR_ENABLE;*/

	puts("Hello, World!\n");
/*    printval();*/
/*    puts("overwrite variables.\n");*/
/*    global_data++;*/
/*    global_bss++;*/
/*    static_data++;*/
/*    static_bss++;*/
/*    printval();*/

	cmd_map();
#if 0
	vec = IntVector_new();
/*    lst = IntList_new();*/

	while (1) {
		static char buf[32];
		char *p;
		PRINTF0(">");
		gets(buf, sizeof buf);
		p = strpbrk(buf, "\r\n");
		if (p) *p = '\0';
		PRINTF1("%s\n", buf);
		if (sw_is_on(SW1)) {
			led_on(LED1);
			i++;
			if (i > 100) {
				i = 0;
				if (IntVector_push_back(vec, data)) {
					PRINTF1("IntVector_push_back: %d", data);
/*                    putdval(data, 0);*/
					data++;
					PRINTF1(", IntVector_size: %d\n", IntVector_size(vec));
/*                    putdval(IntVector_size(vec), 0);*/
/*                    puts("\n");*/
				} else {
					puts("IntVector_push_back: failed\n");
					puts("IntVector_capacity: ");
					putdval(IntVector_capacity(vec), 0);
					puts(", IntVector_size: ");
					putdval(IntVector_size(vec), 0);
					puts("\n");
				}
			}
		} else {
			led_off(LED1);
		}

		if (sw_is_on(SW2)) {
			if (!IntVector_empty(vec)) {
				puts("IntVector_back: ");
				putdval(*IntVector_back(vec), 0);
				puts(", IntVector_pop_back");
				IntVector_pop_back(vec);
				puts("\n");
			}
		}

		if (sw_is_on(SW5_8)) {
			led_on(LED2);
		} else {
			led_off(LED2);
		}

		if (sw_is_on(SW3)) {
			putxval(c++, 0);
			puts("\n");
		}

		if (sw_is_on(SW4)) {
			putdval(c++, 0);
			puts("\n");
		}

	}
#endif
	return 0;
}
