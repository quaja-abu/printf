#include "holberton.h"
int _strlen(const char *);
void print_number(int);

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
  * _strlen - function to find string length
  * @s: character pointer
  *
  * Return: integer value
**/
int _strlen(const char *s)
{
	int val = 0;
	while (s[val] != '\0')
	{
		val++;
	}
	return (val);
}

/**
 *   * _printf - function that prints anything
 *     * @format: charater pointer that takes strings as argument
 *       *
 *         * Return: integer value
 *           */
int _printf(const char *format, ...)
{
	const char *str, *s;
	va_list args;
	int val, len = 0;

	if (format == NULL)
		return (-1);
	len = _strlen(format);
	va_start(args, format);
	for (str = format; *str != '\0'; str++)
	{
		while (*str != '%')
		{
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
				if (s == NULL)
					s = "(null)";
				len += _strlen(s);
				len = len - 2;
				while (*s)
				{
					_putchar(*s);
					s++;
				}
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
	}
	va_end(args);
	return (len);
}
