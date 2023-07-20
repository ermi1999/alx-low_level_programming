#include "main.h"

/**
 * print_line - willprint a straight line using _ to the terminal
 * @n: is the input for how many times the _ will be printed
 */
void print_line(int n)
{
	if (n <= 0)
	{
		_putchar('\n');
	} else
	{
		int i;

		for (i = 1; i <= n; i++)
		{
			_putchar('_');
		}
		_putchar('\n');
	}

}
