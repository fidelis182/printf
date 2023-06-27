#include "main.h"

/**
 * check_precision - checks the precision from string
 * @p: pointer to a string
 * @parameters: specifiers
 * @args: argument pointer
 * Return:  pointer
 */
char *check_precision(char *p, flags_t *params, va_list args)
{
	char k = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		k = (char) va_arg(args, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			k = k * 10 + (*p++ - '0');
	}

	params->precision = k;
	return (p);
}
