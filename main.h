#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>


/**
 * struct format_specifier- stores the format specifiers and
 * their respective functions
 * @symbol: the format specifier symbol
 * @function: the function associated with the symbol
 * @
*/
struct format_specifier
{
	char *symbol;
	int (*function)(va_list);
};
typedef struct format_specifier format_t;

/*All functions related to print directly*/
int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_prcnt(__attribute__((unused)) va_list args);
int print_string(va_list args);
int print_decimal(va_list args);
int get_format_func(const char *format,
format_t format_list[], va_list arg_list);

/*Other functions*/
int power_of_ten(int n);
#endif
