#ifndef MAIN_H
#define MAIN_H

/******** C Standard library headers ********/
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

/******** Macros ********/
#define BUFFER 1024

/******** Typedef and Structs ********/
/**
 * struct conversion - Represents a conversion specifier and
 * its corresponding handler function
 * @specifier: Character representing the conversion specifier
 * @handler: Function pointer to the handler function for the specifier
 */
typedef struct conversion
{
	char specifier;
	int (*handler)(va_list);
} conversion_t;

/******** Function prototypes ********/

int _printf(const char *format, ...);
int _putchar(char c);
int (*get_spec_func(char specifier))(va_list);

int print_char(va_list params);
int print_string(va_list params);
int print_percent(va_list params);
int print_integer(va_list params);
int print_octal(va_list params);
int print_binary(va_list params);
int print_hexa(va_list params);
int print_unsigned_int(va_list params);

#endif /* MAIN_H */
