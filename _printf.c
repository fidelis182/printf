#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
/**
 * _printf- prints out strings according to a format
 * @format: the strings' format
 * Return: printed output
*/

int _printf(const char *format, ...)
{
	int i = 0;
	va_list args;

	va_start(args, format);

	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					print_char(va_arg(args, int));
					break;
				case 's':
					print_string(va_arg(args, char *));
					break;
				case '%':
					print_char('%');
					break;
				case 'd':
					print_int(va_arg(args, int));
					break;
			}
		}
		else
			print_char(format[i]);
		i++;
	}
	va_end(args);
	print_char('\n');
	return (i);
}
