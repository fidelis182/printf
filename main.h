#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>


#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define FIELD_BUF_SIZE 50

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct flags - all the flags 
 *
 * @unsign: flag if unsigned
 * @plus_flag: on if plus_flag
 * @space_flag: if hashtag_flag
 * @hashtag_flag: if _flag specified
 * @zero_flag: flag specified
 * @minus_flag: on if specified
 * @width: field width
 * @precision: field precision
 * @h_modifier: on if its specified
 * @l_modifier: on if its specified
 *
 *
 */

typedef struct flags
{
	unsigned int unsign			: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} flags_t;

int _printf(const char *format, ...);
/* print_specs.c module */
int print_char(va_list args, flags_t *format);
int print_string(va_list args, flags_t *format);
int print_prcent(va_list args, flags_t *format);

int power_of_ten(int n);
int (*check_specifier(char *s))(va_list args, flags_t *format);
char (*get_precision(char *p))(flags_t *format, va_list args);

/**
 * struct conversion_specifier - Structure struct
 * @a: character to compare
 * @f: function
 */
typedef struct f_function
{
	char *symbol;
	int (*f)(va_list, flags_t *);
}func_t;
#endif
