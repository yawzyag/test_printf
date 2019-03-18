#include "holberton.h"

/**
 * printf_int - print numbers
 * @args: argumentos
 *
 * Return: int printed
 */
int printf_oct(va_list args)
{
	unsigned int n;
	n = va_arg(args, unsigned int);

	if (n / 8)
		printnumberoctal(n / 8);

	return (_putchar(n % 8 + '0'));
}