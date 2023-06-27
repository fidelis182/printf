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
		init_params(&params, aps);

		if (*p != '%')
		{
			b += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params))
		{
			p++;
		}
		p = get_width(p, &params, args);
		p = check_precision(p, &params, args);
		if (get_modifier(p, &params))
			p++;
		if (!check_specifier(p))
			b += print_from_to(start, p,
				params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			b += get_print_func(p, args, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(args);
	return (b);
}
