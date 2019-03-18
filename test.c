#include "holberton.h"

/**
 * _printf - printf function
 * @format: format arguments to print
 *
 * Return: number of characters printed
*/
int _printf(const char *format, ...)
{
	operations_t types[] = {
		{"c", printf_char},
		{"s", printf_string},
		{"i", printf_int},
		{"d", printf_dec},
		{NULL, NULL}};

	int j, i = 0, count = 0;
	va_list args;

	va_start(args, format);
	while (format && format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			count += _putchar(format[i]);
			i++;
		}
		if (format[i] != '\0')
			i++;
		else
			break;
		if (format[i] == '%')
			count += _putchar('%');
		else
		{
			for (j = 0; types[j].operation; j++)
			{
				if (*(types[j].operation) == format[i])
					count += types[j].f(args);
			}
		}
		i++;
	}
	va_end(args);
	return (count);
}
