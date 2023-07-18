#include "main.h"

/**
 * is lower check if the charachter is lowercase
 *
 * if the charachter is lowercase return 1 otherwise return 0
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
