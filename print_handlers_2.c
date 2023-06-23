#include "main.h"

/**
 * print_unsigned_int - prints an unsigned integer
 * @params: Argument list containing the unsigned integer to be printed
 *
 * Return: The number of printed characters.
 */
int print_unsigned_int(va_list params)
{
	unsigned int num = va_arg(params, unsigned int);
	int len = 0;

	if (num / 10)
		len += print_unsigned_int(params);
	len += _putchar(num % 10 + '0');

	return (len);
}

/**
 * print_octal - prints an unsigned int in octal format
 * @params: Argument list containing the unsigned int to be printed
 *
 * Return: The number of printed characters.
 */
int print_octal(va_list params)
{
	unsigned int num = va_arg(params, unsigned int);
	char buffer[12];
	int len = 0, i;

	if (num == 0)
		return (_putchar('0'));

	while (num)
	{
		buffer[len++] = num % 8 + '0';
		num /= 8;
	}

	for (i = len - 1; i >= 0; i--)
		_putchar(buffer[i]);

	return (len);
}
