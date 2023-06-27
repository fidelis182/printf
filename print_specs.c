#include "main.h"
/**
 * print_char- prints a character to the standard output
 * @c: the character to be printed
 * Return: number of bytes printed to the standard output
*/
int print_char(va_list args, flags_t *format)
{
	char c = ' ';
	unsigned int i = 1, b = 0, ch = va_arg(args, int);

	if (format->minus_flag)
		b += putchar(ch);
	while (i++ < format->width)
		b += putchar(c);
	if (!format->minus_flag)
		b += putchar(ch);
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

	y = i = strlen(str);
	if (format->precision < i)
		y = i = format->precision;

	if (format->minus_flag)
	{
		if (format->precision != UINT_MAX)
			for (x = 0; x < i; x++)
				b += putchar(*str++);
		else
			b += puts(str);
	}
	while (y++ < format->width)
		b += putchar(c);
	if (!format->minus_flag)
	{
		if (format->precision != UINT_MAX)
			for (x = 0; x < i; x++)
				b += putchar(*str++);
		else
			b += puts(str);
	}
	return (b);
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
	return (putchar('%'));
}

