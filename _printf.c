#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: The format string
 *
 * Return: Number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	int i = 0, printed_chars = 0;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);
			if (format[i] == 'c')
				printed_chars += _char(args);
			else if (format[i] == 's')
				printed_chars += _string(args);
			else if (format[i] == 'd' || format[i] == 'i')
				printed_chars += _integer(args);
			else if (format[i] == '%')
				printed_chars += _putchar('%');
			else
			{
				_putchar('%');
				_putchar(format[i]);
				printed_chars += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		}
		i++;
	}

	va_end(args);
	return (printed_chars);
}

