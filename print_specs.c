#include "main.h"
/**
 * print_char- prints a character to the standard output
 * @c: the character to be printed
 * Return: number of bytes printed to the standard output
*/
int print_char(va_list args, flags_t *format);
{
	char c = ' ';
	unsigned int i = 1, b = 0, ch = va_arg(args, int);

	if (format->minus_flag)
		b += _putchar(ch);
	while (i++ < format->width)
		b += _putchar(c);
	if (!format->minus_flag)
		b += _putchar(ch);
	return (b);
}

/**
 * print_string- prints a string of chars to the standard output
 * @c: the character string
 * Return: number of bytes printed out to the standard output
*/
int print_string(va_list args, flags_t *format)
{
	char *str = va_arg(args, char *), c = ' ';
	unsigned int i = 0, b = 0, x = 0, y;

	(void)format;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = i = _strlen(str);
	if (format->precision < i)
		j = i = format->precision;

	if (format->minus_flag)
	{
		if (format->precision != UINT_MAX)
			for (x = 0; x < i; x++)
				b += _putchar(*str++);
		else
			b += _puts(str);
	}
	while (y++ < format->width)
		b += _putchar(c);
	if (!format->minus_flag)
	{
		if (format->precision != UINT_MAX)
			for (x = 0; x < i; x++)
				b += _putchar(*str++);
		else
			b += _puts(str);
	}
	return (b);
}

/**
 * print_int- prints an integer to the standard output
 * @a: the integer to be printed
 * Return: number of bytes printed to the standard output
*/
int print_int(va_list args, flags_t *format)
{
	long i;

	if (format->i_modifier)
		i = va_arg(args, long);
	else if (format->h_modifier)
		i = (short int)va_arg(args, int);
	else
		i = (int)va_arg(args, int);
	return (print_number(convert(i, 10, 0, format), format));
}
/**
 * print_percent - prints stringto percentage
 * @aps: argument pointer
 * @params: the parameters
 * Return: chars
 */
int print_prcent(va_list args, flags_t *format)
{
	(void)args;
	(void)format;
	return (_putchar('%'));
}

