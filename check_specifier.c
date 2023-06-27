#include "main.h"
/**
 * check_specifier - checks for the specifier
 * @s: string
 * Return: the bytes to be printed
 */
int (*check_specifier(char *s))(va_list args, flags_t *format)
{
	func_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_prcent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int b = 0;

	while (specifiers[b].specifier)
	{
		if (*s == specifiers[b].specifier[0])
		{
			return (specifiers[b].f);
		}
		b++;
	}
	return (NULL);
}
