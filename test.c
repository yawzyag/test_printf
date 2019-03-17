#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct operations
{
	char *operation;
	int (*f)(va_list args);
} operations_t;

int printf_char(va_list args);
int printf_string(va_list args);
int printf_int(va_list args);
int printf_dec(va_list args);
int printnumber(int n);
int _puts(char *str);
int _putchar(char c);
int _printf(const char *format, ...);


int printf_char(va_list args)
{
	return(_putchar(va_arg(args, int)));
}

int printf_string(va_list args)
{
	return(_puts(va_arg(args, char *)));
}

int printf_int(va_list args)
{
	int n = va_arg(args, int);
	if (n < 0) {
		_putchar('-');
		n = -n;
	}

	if (n == 0)
		_putchar('0');

	if (n/10)
		printnumber(n/10);

	return(_putchar(n%10 + '0'));
}

int printf_dec(va_list args)
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

	return(putchar(n%10 + '0'));
}

int printnumber(int n)
{

	if (n < 0) {
		_putchar('-');
		n = -n;
	}

	if (n == 0)
		_putchar('0');

	if (n/10)
		printnumber(n/10);

	return(_putchar(n%10 + '0'));
}

int _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


int _printf(const char *format, ...)
{
	operations_t types[] = {
		{"c", printf_char},
		{"s", printf_string},
		{"i", printf_int},
		{"d", printf_dec},
		{NULL, NULL}
	};

	int j, i = 0, count =0;

	va_list args;

	va_start(args, format);

	while (format && format[i] != '\0')
	{
		while( format[i] != '%' && format[i] != '\0')
		{
		        count += _putchar(format[i]);
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
			count += _putchar('%');
		}
		else
		{
			for (j = 0; types[j].operation; j++)
			{
			        if(*(types[j].operation) == format[i])
				{
					count += types[j].f(args);
				}
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
 

int main() {
    
	char j = 'n';
	char *s = "holberton";
	int i = -3535322;
	int len;
        
	len = _printf("Let's try to printf a simple sentence.\n");
        
	_printf("prueba _printf\n");
	_printf("holi\n%%\n%c\n%s\n%im\n\n", j, s, i);
	printf("prueba print normal\n");
	printf("holi\n%%\n%c\n%s\n%ip\n\n", j, s, i);


	_printf("Length:[%i]\n", len);

	_printf("test of holberton\n");
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");

	return 0;
}
