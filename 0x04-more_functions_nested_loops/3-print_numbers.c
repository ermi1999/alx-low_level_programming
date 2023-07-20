#include "main.h"

/**
 * print_numbers - function will print the numbers 0-9
 *
 * Return: will be void
 */
void print_numbers(void)
{
	char c;

	for (c = '0'; c <= '9'; c++)
	{
		_putchar(c);
	}
	_putchar('\n');
}
