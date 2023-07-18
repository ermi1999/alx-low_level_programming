#include "main.h"

/**
 * _islower - checks if the character is lowercase
 * @c: placeholder for charachter to be checked
 * Return: if the character is lowercase return 1 otherwise returns 0.
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
