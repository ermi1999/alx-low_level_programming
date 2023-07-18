#include "main.h"

/**
 * checks for alphabetic character
 *
 * return 1 if it is a letter otherwise 0
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
