#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);

int _strlen(const char *)
{
	int j = 0;
	int count = 0;

	while (*(s + j) != '\0')
	{
		count = count + 1;
		i++;
	}
	return (count);
}

int _putchar(const char *)
{
		int c;
	        return (write(1, &c, 1));
}

#endif /* HOLBERTON_H */
