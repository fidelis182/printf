#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
/**
 * get_format_func- prints a formatted string
 * @format: a string of chars
 * @format_list: a list of format specifiers and their functions
 * @arg_list: list of variable arguments
 * Return: the number of characters printed
*/

int get_format_func(const char *format, format_t format_list[],
			va_list arg_list)
{
	int i, j = 0, retrn_val, chars_printed;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; format_list[j].symbol != NULL; j++)
			{
				if (format[i + 1] == format_list[j].symbol[0])
				{
					retrn_val = format_list[j].function(arg_list);
					if (retrn_val == -1)
						return (-1);
					chars_printed += retrn_val;
					break;
				}
			}
			if (format_list[j].symbol == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					chars_printed = chars_printed + 2;
				}
				else
					return (-1);
			}
			i++;
		}
		else
		{
			_putchar(format[i]);
			chars_printed++;
		}
	}
	return (chars_printed);
}
