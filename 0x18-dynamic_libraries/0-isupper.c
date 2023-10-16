#include "main.h"

/**
 * _isupper - checks if letter is uppercase
 * @c: the letter to check
 *
 * Return: 0 if the char is uppercase 1 if the char is lowercase
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
