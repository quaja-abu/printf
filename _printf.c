#include "holberton.h"
int print_s(const char *, int);
/**
 *  _printf - function that prints anything
 *  @format: charater pointer that takes strings as argument
 *
 *  * Return: integer value
 **/
int _printf(const char *format, ...)
{
	const char *str, *s;
	va_list args;
	int val, len = 0;

	if (format == NULL)
		return (-1);

	len += _strlen(format);
	if (*format == '%' && len == 1)
		return (-1);
	va_start(args, format);
	for (str = format; *str != '\0'; str++)
	{
		while (*str != '%')
		{
			if (*str != '\0')
				_putchar(*str);
			if (*str == '\0')
				break;
			str++;
		}
		if (*str == '\0')
			break;
		str++;
		switch (*str)
		{
			case 'c':
				val = va_arg(args, int);
				_putchar(val);
				break;
			case 's':
				s = va_arg(args, char *);
				len = print_s(s, len);
				break;
			case '%':
				_putchar(*str);
				break;
			case 'd':
				val = va_arg(args, int);
				print_number(val);
				break;
			case 'i':
				val = va_arg(args, int);
				print_number(val);
				break;
			default:
				_putchar('%');
				_putchar(*str);
				break;
		}
		len--;
	}
	va_end(args);
	return (len);
}

/**
  * _strlen - function to find string length
  * @s: character pointer
  *
  * Return: integer value
  */

int _strlen(const char *s)
{
	int val = 0, i = 0;

	while (s[val] != '\0')
	{
		++val;
	}
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] == 's')
			val--;
		i++;
	}
	return (val);
}

/**
 * print_number - to print any number using _putchar
 * @n: integer value
 */

void print_number(int n)
{
	unsigned int x;

	x = n;
	if (n == 0)
	{
		_putchar('0');
		return;
	}
	if (n < 0)
	{
		_putchar(45);
		x = -n;
	}
	if (x / 10)
	{
		print_number(x / 10);
	}
	_putchar((x % 10) + '0');
}
/**
  * print_s - function to print the string
  * @s: character constant pointer
  * @len: string length
  *
  * Return: string length
  */
int print_s(const char *s, int len)
{
	if (s == NULL)
		s = "(null)";
	len += _strlen(s);
		while (*s)
		{
			_putchar(*s);
			s++;
		}
	return (len);
}
