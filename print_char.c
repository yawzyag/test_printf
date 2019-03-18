#include "holberton.h"

int printf_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}