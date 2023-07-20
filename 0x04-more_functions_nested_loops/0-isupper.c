#include "main.h"

/**
 * _isupper - checks if the characters is uppercase letters
 * @c: the character to be checked
 *
 * Return: 0 or 1 depending on the char
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

