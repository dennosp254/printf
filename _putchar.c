#include "main.h"

/**
 * _putchar - writes the character c to the stdout
 * @c: character to be printed
 *
 * Return: The character written to a char cast as an int.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
