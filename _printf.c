#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 * @...: Variable number of arguments corresponding to the format specifier
 *
 * Return: The number of characters to be printed
 * excluding the null byte used to end output to strings
 */
int _printf(const char *format, ...)
{
	va_list params;
	int (*handler)(va_list);
	int fmt_ind = 0, print_count = 0;

	va_start(params, format);
	while (format[fmt_ind])
	{
		if (format[fmt_ind] == '%')
		{
			fmt_ind++;
			handler = get_spec_func(format[fmt_ind]);

			if (handler == NULL)
			{
				print_count += _putchar('%');
				print_count += _putchar(format[fmt_ind]);
			}
			else
				print_count += handler(params);
		}
		else
			print_count += _putchar(format[fmt_ind]);

		fmt_ind++;
	}

	va_end(params);
	return (print_count);
}
