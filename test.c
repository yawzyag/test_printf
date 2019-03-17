/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdarg.h>

typedef struct operations
{
	char *operation;
	int (*f)(va_list args);
} operations_t;

void printf_char(va_list args);
void printf_string(va_list args);
void printf_int(va_list args);
void printf_dec(va_list args);
void printnumber(int n);
int _printf(const char *format, ...);

int _printf(const char *format, ...)
{
	operations_t types[] = {
		{"c", printf_char},
		{"s", printf_string},
		{"i", printf_int},
		{"d", printf_dec},
		{NULL, NULL}
	};

	int j, i = 0, count = 0;

	va_list args;

	va_start(args, format);

	while (format && format[i] != '\0')
	{
		while( format[i] != '%' && format[i] != '\0')
		{
		        putchar(format[i]);
		        i++;
		}
		if(format[i] != '\0')
		{
		        i++;
		}
		else 
		{
			break;
		}
		if(format[i] == '%')
		{
			putchar('%');
		}
		else
		{
			for (j = 0; types[j].operation; j++)
			{
			        if(*(types[j].operation) == format[i])
				{
					types[j].f(args);
					count + 1;
				}
			}
		}
		i++;
	}
}

void printf_char(va_list args)
{
	putchar(va_arg(args, int));
}

void printf_string(va_list args)
{
	_puts(va_arg(args, char *));
}

void printf_int(va_list args)
{
	int n = va_arg(args, int);
	if (n < 0) {
		putchar('-');
		n = -n;
	}

	if (n == 0)
		putchar('0');

	if (n/10)
		printnumber(n/10);

	putchar(n%10 + '0');
}

void printf_dec(va_list args)
{
	int n = va_arg(args, int);
	if (n < 0) {
		putchar('-');
		n = -n;
	}

	if (n == 0)
		putchar('0');

	if (n/10)
		printnumber(n/10);

	putchar(n%10 + '0');
}

void printnumber(int n)
{

	if (n < 0) {
		putchar('-');
		n = -n;
	}

	if (n == 0)
		putchar('0');

	if (n/10)
		printnumber(n/10);

	putchar(n%10 + '0');
}

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		putchar(str[i]);
	}
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
 

int main() {
	char j = 'n';
	char *s = "holberton";
	int i = -3535322;
	_printf("holi\n%%\n%c\n%s\n%i", j, s, i);
	return 0;
}
