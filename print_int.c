#include "holberton.h"

/**
 * printf_int - print numbers
 * @args: argumentos
 *
 * Return: int printed
 */
int printf_int(va_list args)
{
	int n = va_arg(args, int);

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	if (n == 0)
		_putchar('0');

	if (n / 10)
		printnumber(n / 10);

	return (_putchar(n % 10 + '0'));
}
