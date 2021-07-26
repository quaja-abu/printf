#include "holberton.h"

/**
  * _printf - function that prints anything
  * @format: charater pointer that takes strings as argument
  *
  * return: integer value
  */
int _printf(const char *format, ...)
{
	const char *str, *s;
	va_list args;
	int i = 0, val;

	va_start(args, format);
	for (str = format; *str != '\0'; str++)
	{
		while (*str != '%')
		{
			putchar(*str);
			if (*str == '\0')
				break;
			str++;
			i++;
		}
		if (*str == '\0')
			break;
		str++;
		switch (*str)
		{
			case 'c':
				val = va_arg(args, int);
				putchar(val);
				break;
			case 's':
				s = va_arg(args, char *);
				puts(s);
				break;
			default:
				break;
		}
	}
	va_end(args);
	return (i);
}
