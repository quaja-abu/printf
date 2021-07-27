#include "holberton.h"
/**
  * _printf - function that prints anything
  * @format: charater pointer that takes strings as argument
  *
  * Return: integer value
  */
int _printf(const char *format, ...)
{
	const char *str, *s;
	va_list args;
	int len; 
	int val;
	int i;

	len = _strlen(format);
	va_start(args, format);
	for (str = 0; str != '\0'; str++)
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
				while (*s)
				{
					putchar(*s);
					s++;
				}
			/*	puts(s);*/
				break;
			case '%':
				putchar(*str);
				break;
			default:
				putchar('%');
				putchar(*str);
				break;
		}
	}
	va_end(args);
	return (i);
}
