#include "main.h"

/**
 * get_precision - checks the precision from string
 * @p: pointer to a string
 * @format: parameters
 * @args: argument pointer
 * Return:  pointer
 */
char (*get_precision(char *p))(flags_t *format, va_list args)
{
	int e = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		e = va_arg(args, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			e =e * 10 + (*p++ - '0');
	}

	format->precision = e;
	return (p);
}
