#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
/**
 * _printf- produces output according to a format
 * @format: the format to be output
 * Return: the numbe rof chaacters printed
 */
int _printf(const char *format, ...)
{
int chars_printed;

format_t list_format[] = {
	{"c", print_char},
	{"s", print_string},
	{"%", print_prcnt},
	{"d", print_decimal},
	{"i", print_decimal},
	{NULL, NULL}
};

va_list args;
	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	chars_printed = get_format_func(format, list_format, args);
	va_end(args);
	return (chars_printed);
}
