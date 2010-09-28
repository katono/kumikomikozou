#ifndef STD_STRING_H_INCLUDED
#define STD_STRING_H_INCLUDED

#include "stddef.h"

void *memset(void *b, int c, size_t len);
void *memcpy(void *dst, const void *src, size_t len);
void *memmove(void *dst, const void *src, size_t len);
int memcmp(const void *b1, const void *b2, size_t len);
size_t strlen(const char *s);
char *strcpy(char *dst, const char *src);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t len);

#endif /* STD_STRING_H_INCLUDED */
