# printf C implementation
This is the implementation of the standard library's printf function in the C programming language
It handles all the format specifiers.
Done in order to understand variadic functions in C

## Testing the function
```bash
gcc -Wall -Wextra -pedantic -std=gnu89 main.c _printf.c functions.c -o a
./a
```
## Authors
 [Destiny](https://github.com/Destiny-Kay) and [Fidelis](https://github.com/fidelis182)

files that I have to create from my printf
	get_width.c
	get_flag.c
	check_precision.c
	get_modifier.c
	check_specifier.c
	print_range.c
	get_print_func.c
	initialize_parameters.c
	print_numbers.c
	isdigit.c
