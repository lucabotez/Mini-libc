// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	char *c;
	for(c = source; *c != '\0'; c++) {
		*destination = *c;
		destination++;
	}

	*destination = *c;
	return destination;
}

// implementare: https://opensource.apple.com/source/Libc/Libc-262/i386/gen/strncpy.c.auto.html
char *strncpy(char *destination, const char *source, size_t len)
{
	if (len != 0) {
		register char *d = destination;
		register const char *s = source;

		do {
			if ((*d++ = *s++) == 0) {
				/* NUL pad the remaining n-1 bytes */
				while (--len != 0)
					*d++ = 0;
				break;
			}
		} while (--len != 0);
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	for(destination; *destination != '\0'; destination++) {}

	char *c;
	for(c = source; *c != '\0'; c++) {
		*destination = *c;
		destination++;
	}

	*destination = *c;
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	for(destination; *destination != '\0'; destination++) {}

	char *c;
	for(c = source; len; c++, len--) {
		*destination = *c;
		destination++;
	}

	*destination = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0') {
		if ((*str1) < (*str2))
			return -1;
		else if ((*str1) > (*str2))
			return 1;

		str1++;
		str2++;
	}

	if (*str1 == '\0' && *str2 != '\0')
		return -1;
	else if (*str1 != '\0' && *str2 == '\0')
		return 1;

	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	while (len) {
		if ((*str1) < (*str2))
			return -1;
		else if ((*str1) > (*str2))
			return 1;

		str1++;
		str2++;

		if(*str1 == '\0' || *str2 == '\0')
			break;

		len--;
	}

	if (!len) {
		if (*str1 == '\0' && *str2 != '\0')
			return -1;
		else if (*str1 != '\0' && *str2 == '\0')
			return 1;

		return 0;
	}

	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	for (; *str != '\0'; str++) {
		if (*str == c)
			return str;
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	char *pointer = NULL;

	for (; *str != '\0'; str++) {
		if (*str == c)
			pointer = str;
	}
	return pointer;
}

char *strstr(const char *haystack, const char *needle)
{
	char *h, *n;
	char *initial_pointer;

	int check = 0;

	n = needle;
	for (h = haystack; *h != '\0'; h++) {
		if (*n == '\0')
			return initial_pointer;

		if (*h == *n && check == 0) {
			initial_pointer = h;
			check = 1;
			n++;
		} else if (*h == *n && check == 1) {
			n++;
		} else {
			n = needle;
			check = 0;
		}
	}

	return NULL;
}

// implementare: https://elixir.bootlin.com/busybox/latest/source/libbb/strrstr.c
char *strrstr(const char *haystack, const char *needle)
{
	char *r = NULL;

	if (!needle[0])
		return (char*)haystack + strlen(haystack);
	while (1) {
		char *p = strstr(haystack, needle);
		if (!p)
			return r;
		r = p;
		haystack = p + 1;
	}
}

// implementare: ChatGPT
void *memcpy(void *destination, const void *source, size_t num)
{
	char* dest = (char*)destination;
    const char* src = (const char*)source;

    for (size_t i = 0; i < num; i++) {
        dest[i] = src[i];
    }

    return destination;
}

// implementare: ChatGPT
void *memmove(void *destination, const void *source, size_t num)
{
	char* dst = (char*)destination;
    const char* src = (const char*)source;

    if (dst == src) {
        return destination;
    }

    if (src < dst && dst < src + num) {
        for (size_t i = num; i > 0; i--) {
            dst[i - 1] = src[i - 1];
        }
    } else {
        for (size_t i = 0; i < num; i++) {
            dst[i] = src[i];
        }
    }

    return destination;
}

// implementare: https://opensource.apple.com/source/Libc/Libc-262/string/memcmp.c.auto.html
int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	if (num != 0) {
		register const unsigned char *p1 = ptr1, *p2 = ptr2;

		do {
			if (*p1++ != *p2++)
				return (*--p1 - *--p2);
		} while (--num != 0);
	}
	return (0);
}

// implementare: ChatGPT
void *memset(void *source, int value, size_t num)
{
	unsigned char* p = (unsigned char*)source;
    for (size_t i = 0; i < num; i++) {
        p[i] = (unsigned char)value;
    }
    return source;
}
