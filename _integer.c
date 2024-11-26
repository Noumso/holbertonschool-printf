#include "main.h"
/**
 * _integer - print integer
 * @args: The argument list
 *
 * Return: Number of characters printed
 */
int _integer(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	char buffer[12];
	unsigned int num;
	int i = 0;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	do {
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);

	while (i--)
	{
		count += _putchar(buffer[i]);
	}

	return (count);
}
