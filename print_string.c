#include "holberton.h"

int printf_string(va_list args)
{
	return (_puts(va_arg(args, char *)));
}