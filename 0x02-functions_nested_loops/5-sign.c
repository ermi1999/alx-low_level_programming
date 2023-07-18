#include "main.h"

/**
 * print_sign - prints the sign of a number
 * @n: placeholder for the number to be checked
 * Return: 1 and print + if the number is greater than 0
 * 0 if it is 0 it prints 0
 * -1 if the number is less than 0
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	} else if (n == 0)
	{
		_putchar(48);
		return (0);
	} else if (n < 0)
	{
		_putchar('-');
	}
		return (-1);
}

