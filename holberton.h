#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);

int _putchar(char c)
{
	return (write(1, &c, 1));
};

#endif /* HOLBERTON_H */
