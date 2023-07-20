#include "main.h"

/**
 * print_most_numbers - will print most numbers except 2 and 4
 * return: the return value will be void
 */
void print_most_numbers(void)
{
	char c;

	for (c = '0'; c <= '9'; c++)
	{
		if (!(c == '2' || c == '4'))
			_putchar(c);
	}
	_putchar('\n');
}
