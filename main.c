#include "holberton.h"

int main()
{

	char j = 'n';
	char *s = "holberton";
	int i = 0x42451;
	int len;

	len = _printf("Let's try to printf a simple sentence.\n");

	_printf("prueba _printf\n");
	_printf("holi\n%%\n%c\n%s\n%dm\n\n", j, s, i);
	printf("prueba print normal\n");
	printf("holi\n%%\n%c\n%s\n%dp\n\n", j, s, i);

	_printf("Length:[%i]\n", len);

	_printf("test of holberton\n");
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");

	return 0;
}