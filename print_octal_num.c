#include "holberton.h"

/**
 * printnumber - function to print digit
 * @n: num
 *
 * Return: void
 */
int printnumberoctal(unsigned int n)
{
	if (n / 8)
		printnumberoctal(n / 8);

	return (_putchar(n % 8 + '0'));
}
