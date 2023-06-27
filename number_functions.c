#include "main.h"

/**
 * power_of_ten- returns a number * 10 raised n times
 * @n: number of times we should raise 10
 * Return: A number raised to n
*/
int power_of_ten(int n)
{
	int result = 1;

	while (n > 0)
	{
		result *= 10;
		n--;
	}
	return (result);
}
