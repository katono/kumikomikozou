#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../lib.h"

#undef strtol
#undef strtoul
#undef printf

#define CHECK_STRTOL(s, b)	check_strtol(s, b, __FILE__, __LINE__)
#define CHECK_STRTOUL(s, b)	check_strtoul(s, b, __FILE__, __LINE__)

static void check_strtol(const char *s, int base, const char *file, int line)
{
	long ret1, ret2;
	char *p1, *p2;
	ret1 = strtol(s, &p1, base);
	ret2 = my_strtol(s, &p2, base);
	if (base == 10) {
		printf("%s(%d): strtol[%ld], my_strtol[%ld]\n", file, line, ret1, ret2);
	} else {
		printf("%s(%d): strtol[%#lx], my_strtol[%#lx]\n", file, line, ret1, ret2);
	}
	assert(ret1 == ret2);
/*    printf("p1[%d], p2[%d]\n", p1 - s, p2 - s);*/
	assert(p1 == p2);
}

static void check_strtoul(const char *s, int base, const char *file, int line)
{
	unsigned long ret1, ret2;
	char *p1, *p2;
	ret1 = strtoul(s, &p1, base);
	ret2 = my_strtoul(s, &p2, base);
	if (base == 10) {
		printf("%s(%d): strtoul[%ld], my_strtoul[%ld]\n", file, line, ret1, ret2);
	} else {
		printf("%s(%d): strtoul[%#lx], my_strtoul[%#lx]\n", file, line, ret1, ret2);
	}
	assert(ret1 == ret2);
/*    printf("p1[%d], p2[%d]\n", p1 - s, p2 - s);*/
	assert(p1 == p2);
}

void test_strtol(void)
{
	CHECK_STRTOL("0", 10);
	CHECK_STRTOL("0000", 10);
	CHECK_STRTOL("123", 10);
	CHECK_STRTOL("-0", 10);
	CHECK_STRTOL("-123", 10);
	CHECK_STRTOL("- 123", 10);
	CHECK_STRTOL("	-123", 10);
	CHECK_STRTOL("+0", 10);
	CHECK_STRTOL("+123", 10);
	CHECK_STRTOL("+ 123", 10);
	CHECK_STRTOL("	+123", 10);
	CHECK_STRTOL("  123aa", 10);
	CHECK_STRTOL(" 	 123	 	", 10);
	CHECK_STRTOL("zzz123zzz", 10);
	CHECK_STRTOL("0x123", 10);
	CHECK_STRTOL("zzz", 10);

	CHECK_STRTOL("0", 16);
	CHECK_STRTOL("0000", 16);
	CHECK_STRTOL("0x0000", 16);
	CHECK_STRTOL("123", 16);
	CHECK_STRTOL("- 0123", 16);
	CHECK_STRTOL("-0123", 16);
	CHECK_STRTOL("-0", 16);
	CHECK_STRTOL("-0x0", 16);
	CHECK_STRTOL("+ 0123", 16);
	CHECK_STRTOL("+0123", 16);
	CHECK_STRTOL("+0", 16);
	CHECK_STRTOL("+0x0", 16);
	CHECK_STRTOL("0x123", 16);
	CHECK_STRTOL("0x7eadBeef", 16);
	CHECK_STRTOL("0X7EADBEEF", 16);
	CHECK_STRTOL("	0012a", 16);
	CHECK_STRTOL("  123aa", 16);
	CHECK_STRTOL(" 	 123	 	", 16);
	CHECK_STRTOL("zzz123zzz", 16);
	CHECK_STRTOL("1zzz123zzz", 16);
	CHECK_STRTOL("0z", 16);
	CHECK_STRTOL("0x", 16);
	CHECK_STRTOL("0xz", 16);
	CHECK_STRTOL("0xZ123", 16);
	CHECK_STRTOL("0xx123", 16);
	CHECK_STRTOL("zzz", 16);

	CHECK_STRTOL("0x123", 0);
	CHECK_STRTOL("-0xABCD", 0);
	CHECK_STRTOL("123", 0);
	CHECK_STRTOL("-123", 0);
	CHECK_STRTOL("+123", 0);
	CHECK_STRTOL("1A3", 0);
	CHECK_STRTOL("zzz", 0);
}

void test_strtoul(void)
{
	CHECK_STRTOUL("0", 10);
	CHECK_STRTOUL("0000", 10);
	CHECK_STRTOUL("123", 10);
	CHECK_STRTOUL("-0", 10);
	CHECK_STRTOUL("-123", 10);
	CHECK_STRTOUL("- 123", 10);
	CHECK_STRTOUL("	-123", 10);
	CHECK_STRTOUL("  123aa", 10);
	CHECK_STRTOUL(" 	 123	 	", 10);
	CHECK_STRTOUL("zzz123zzz", 10);
	CHECK_STRTOUL("zzz", 10);

	CHECK_STRTOUL("0", 16);
	CHECK_STRTOUL("0000", 16);
	CHECK_STRTOUL("0x0000", 16);
	CHECK_STRTOUL("123", 16);
	CHECK_STRTOUL("0123", 16);
	CHECK_STRTOUL("-0", 16);
	CHECK_STRTOUL("-0123", 16);
	CHECK_STRTOUL("0x123", 16);
	CHECK_STRTOUL("-0x123", 16);
	CHECK_STRTOUL("-0x0", 16);
	CHECK_STRTOUL("- 0x123", 16);
	CHECK_STRTOUL("0xDeadBeef", 16);
	CHECK_STRTOUL("0XDEADBEEF", 16);
	CHECK_STRTOUL("-0XDEADBEEF", 16);
	CHECK_STRTOUL("	0012a", 16);
	CHECK_STRTOUL("  123aa", 16);
	CHECK_STRTOUL(" 	 123	 	", 16);
	CHECK_STRTOUL("zzz123zzz", 16);
	CHECK_STRTOUL("1zzz123zzz", 16);
	CHECK_STRTOUL("0z", 16);
	CHECK_STRTOUL("0x", 16);
	CHECK_STRTOUL("0xz", 16);
	CHECK_STRTOUL("0xZ123", 16);
	CHECK_STRTOUL("0xx123", 16);
	CHECK_STRTOUL("zzz", 16);

	CHECK_STRTOUL("0x123", 0);
	CHECK_STRTOUL("-0xABCD", 0);
	CHECK_STRTOUL("123", 0);
	CHECK_STRTOUL("-123", 0);
	CHECK_STRTOUL("+123", 0);
	CHECK_STRTOUL("1A3", 0);
	CHECK_STRTOUL("zzz", 0);
}


