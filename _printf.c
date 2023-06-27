#include "main.h"

/**
 * _printf- prints out strings according to a format
 * @format: the strings' format
 * Return: printed output
*/

int _printf(const char *format, ...)
{
	int b = 0;
	va_list args;
	char *p, *start;
	flags_t params = PARAMS_INIT;

	va_start(args, format);

	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		if (*p != '%')
		{
			b += _putchar(*p);
			continue;
		}
		start = p;
		p++;
	}
	_putchar(BUF_FLUSH);
	va_end(args);
	return (b);
}
