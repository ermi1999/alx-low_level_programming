#include "main.h"

/**
 * _isalpha - checks for alphabetic character
 *@c: the character that is going to be checked
 * Return: 1 if it is a letter otherwise 0
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
