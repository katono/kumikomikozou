#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "../lib.h"
#undef strcmp
#undef printf
#undef sprintf

void test_sprintf(void)
{
	static char buf[1024];
	static char sp_buf[1024];

	sprintf(sp_buf, "hogehoge");
	my_sprintf(buf, "hogehoge", 0, 0, 0, 0);
	printf("%s\n", buf);
	assert(strcmp(buf, sp_buf) == 0);

	sprintf(sp_buf, "%s", "piyopiyo");
	my_sprintf(buf, "%s", (unsigned long)"piyopiyo", 0, 0, 0);
	printf("%s\n", buf);
	assert(strcmp(buf, sp_buf) == 0);

	sprintf(sp_buf, "foo%%bar%s", "hoge");
	my_sprintf(buf, "foo%%bar%s", (unsigned long)"hoge", 0, 0, 0);
	printf("%s\n", buf);
	assert(strcmp(buf, sp_buf) == 0);

	sprintf(sp_buf, "%d, %d, %d, \"%8d\"", 9999, 0, -1, -1234);
	my_sprintf(buf, "%d, %d, %d, \"%8d\"", 9999, 0, -1, -1234);
	printf("%s\n", buf);
	assert(strcmp(buf, sp_buf) == 0);

	sprintf(sp_buf, "%u, %u, %-d, \"%-8d\"", 12345, 0, -123, -111);
	my_sprintf(buf, "%u, %u, %-d, \"%-8d\"", 12345, 0, -123, -111);
	printf("%s\n", buf);
	assert(strcmp(buf, sp_buf) == 0);

	sprintf(sp_buf, "\"%d\", \"%8d\", \"%-8d\", \"%s\"", 123456789, 123456, 789, "abcd");
	my_sprintf(buf, "\"%d\", \"%8d\", \"%-8d\", \"%s\"", 123456789, 123456, 789, (unsigned long)"abcd");
	printf("%s\n", buf);
	assert(strcmp(buf, sp_buf) == 0);

	sprintf(sp_buf, "\"%s\", \"%9d\", \"%s\", \"%s\"", "foo", 1234567890, "bar", "abcd");
	my_sprintf(buf, "\"%s\", \"%9d\", \"%s\", \"%s\"", (unsigned long)"foo", 1234567890, (unsigned long)"bar", (unsigned long)"abcd");
	printf("%s\n", buf);
	assert(strcmp(buf, sp_buf) == 0);

	sprintf(sp_buf, "%x, \"%8x\", \"%08X\", \"%10d\"", 0x1234, 0x5678, 0xABCD, 12345);
	my_sprintf(buf, "%x, \"%8x\", \"%08X\", \"%10d\"", 0x1234, 0x5678, 0xABCD, 12345);
	printf("%s\n", buf);
	assert(strcmp(buf, sp_buf) == 0);

	sprintf(sp_buf, "%x, \"%8x\", \"%-8X\", \"%-10d\"", 0x0, 0x5678, 0xABCD, 12345);
	my_sprintf(buf, "%x, \"%8x\", \"%-8X\", \"%-10d\"", 0x0, 0x5678, 0xABCD, 12345);
	printf("%s\n", buf);
	assert(strcmp(buf, sp_buf) == 0);

	sprintf(sp_buf, "%c, %c, %c, %c", 'a', '#', '\\', '9');
	my_sprintf(buf, "%c, %c, %c, %c", 'a', '#', '\\', '9');
	printf("%s\n", buf);
	assert(strcmp(buf, sp_buf) == 0);

	sprintf(sp_buf, "%p, %p, %p, %p", (void *)0, (void *)buf, (void *)sp_buf, (void *)0);
	my_sprintf(buf, "%p, %p, %p, %p", 0, (unsigned long)buf, (unsigned long)sp_buf, 0);
	printf("%s\n", sp_buf);
	printf("%s\n", buf);

}


