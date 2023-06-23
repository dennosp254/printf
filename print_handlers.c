#include "main.h"

/**
 * print_char - prints a character
 * @params: Argument list containing the character
 * to be printed
 *
 * Return: The number of printed characters.
 */
int print_char(va_list params)
{
	char c = va_arg(params, int);

	return (_putchar(c));
}

/**
 * print_string - prints a string
 * @params: Argument list containing the character
 * to be printed
 *
 * Return: The number of printed characters.
 */
int print_string(va_list params)
{
	char *str = va_arg(params, char *);
	int len = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		len += _putchar(*str);
		str++;
	}

	return (len);
}

/**
 * print_percent - prints a percent symbol
 * @params: Argument list
 *
 * Return: The number of printed characters.
 */
int print_percent(va_list params)
{
	(void)params;

	return (_putchar('%'));
}

/**
 * print_integer - prints an integer
 * @params: Argument list containing the integer
 * to be printed
 *
 * Return: The number of printed characters.
 */
int print_integer(va_list params)
{
	int len = 0, div = 1;
	int num = va_arg(params, int);

	if (num == 0)
		return (_putchar('0'));

	if (num < 0)
	{
		len += _putchar('-');
		num = -num;
	}

	while (num / div > 9)
		div *= 10;

	while (div != 0)
	{
		len += _putchar(num / div + '0');
		num %= div;
		div /= 10;
	}

	return (len);
}

/**
 * print_binary - prints an unsigned int in binary format
 * @params: Argument list containing the unsigned int to be printed
 *
 * Return: The number of printed characters.
 */
int print_binary(va_list params)
{
	unsigned int num = va_arg(params, unsigned int);
	int len = 0, i;
	char binary[50];

	if (num == 0)
	{
		len += _putchar('0');
		return (len);
	}

	for (i = 0; num > 0; i++)
	{
		binary[i] = num % 2 + '0';
		num /= 2;
	}
	i--;

	for (; i >= 0; i--)
		len += _putchar(binary[i]);

	return (len);
}
