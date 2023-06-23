#include "main.h"

/**
 * get_spec_func - Finds the function corresponding to a format specifier
 * @specifier: the format specifier character
 *
 * Return: a pointer to the function that handles the specifier,
 * or NULL if not found
 */
int (*get_spec_func(char specifier))(va_list)
{
	conversion_t specifiers[] = {
		{'s', print_string}, {'c', print_char}, {'%', print_percent},
		{'i', print_integer}, {'d', print_integer},
		{'b', print_binary}, {'u', print_unsigned_int},
		{'o', print_octal}, {0, NULL}
	};
	int i = 0;

	while (specifiers[i].handler != NULL)
	{
		if (specifiers[i].specifier == specifier)
			return (specifiers[i].handler);
		i++;
	}
	return (NULL);
}
