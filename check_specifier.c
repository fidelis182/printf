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
		{"s", print_string},
		{"%", print_prcent},
		{NULL, NULL}
	};
	int b = 0;

	while (specifiers[b].symbol != NULL)
	{
		if (*s == specifiers[b].symbol[0])
		{
			return (specifiers[b].f);
		}
		b++;
	}
	return (NULL);
}
