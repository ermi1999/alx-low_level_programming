#include "main.h"

/**
 * _isdigit - function will check if the nuber is between 0 - 9
 * @c: the character to be checked
 *
 * Return: 0 if the number is between 0-9  return 1 if not
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

