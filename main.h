#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
int _printf(const char *format, ...);
int print_char(char c);
int print_string(char *c);
int print_int(int a);
int power_of_ten(int n);
struct f_function
{
	char *symbol;
	int (*f)(va_list);
};
#endif
