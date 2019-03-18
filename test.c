#include "holberton.h"

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

/*char *digit_num(unsigned int num, int base) 
{ 
static char Representation[]= "0123456789ABCDEF";
static char buffer[50]; 
char *ptr; 
ptr = &buffer[49]; 
*ptr = '\0'; 
do 
{ 
*--ptr = Representation[num%base]; 
num /= base; 
}while(num != 0); 
return(ptr); 
}*/
