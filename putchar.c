#include "main.h"
/**
 * _putchar - writes chars to stdout
 * @c: the character
 * Return: On success 1 On error, -1 if null
 */
int _putchar(int c)
{
	static int j;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || j >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, j);
		j = 0;
	}
	if (c != BUF_FLUSH)
		buf[j++] = c;
	return (1);
}
