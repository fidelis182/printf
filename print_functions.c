#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
#include <unistd.h>
/*THIS FILE CONTAINS ALL THE PRINT FUNCTION TO BE USED */

/**
 * _putchar- prints a single character to the standard output
 * @c: the character to be printed
 * Return: a character
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char- prints a single character to stdout
 * @args: the argument with a char in it
 * Return: 1 on success
*/
int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 * print_prcnt- prints the '%' character
 * @args: argument vars
 * Return: 1 on success
*/
int print_prcnt(__attribute__((unused)) va_list args)
{
	_putchar('%');
	return (1);
}
/**
 * print_string- prints a string of char to stdout
 * @args: arguments passed from var args
 * Return: number of chars on success, -1 on fail
*/
int print_string(va_list args)
{
	int i = 0;
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\0');
	return (i);
}
/**
 * print_decimal- prints a decimal number to the standard output
 * @args: argument variables from _printf invocation
 * Return: 0 on success
*/
int print_decimal(va_list args)
{
	int digitCount = 1;
	int temp;
	int a = va_arg(args, int);

	if (a < 0)
	{
		_putchar('-');
		a = -a;
	}
	temp = a;
	/*Getting the number of digits in the number a*/
	while (temp >= 10)
	{
		temp /= 10;
		digitCount++;
	}
	while (digitCount > 0)
	{
		int digit;

		digit = a / power_of_ten(digitCount - 1);
		_putchar('0' + digit);
		a %= power_of_ten(digitCount - 1);
		digitCount--;
	}
	return (digitCount);
}
