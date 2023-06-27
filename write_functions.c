#include "main.h"
#include <stdlib.h>
#include <unistd.h>
/**
 * print_char- prints a character to the standard output
 * @c: the character to be printed
 * Return: number of bytes printed to the standard output
*/
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string- prints a string of chars to the standard output
 * @c: the character string
 * Return: number of bytes printed out to the standard output
*/
int print_string(char *c)
{
	int i = 0;

	while (c[i] != '\0')
	{
		print_char(c[i]);
		i++;
	}
	return (i);
}

/**
 * print_int- prints an integer to the standard output
 * @a: the integer to be printed
 * Return: number of bytes printed to the standard output
*/
int print_int(int a)
{
	int digitCount = 1;
	int temp;

	if (a < 0)
	{
		print_char('-');
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
		print_char('0' + digit);
		a %= power_of_ten(digitCount - 1);
		digitCount--;
	}
	return (0);
}
