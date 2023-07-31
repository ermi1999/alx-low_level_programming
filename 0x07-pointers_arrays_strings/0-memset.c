#include "main.h"
/**
 * _memset - fills the first n bytes of the memory
 * area pointed to by s with the constant byte b
 * @s: memory to be filled
 * @b: desired value
 * @n: the number of values that is going to be changed
 * Return: changed array
 */

char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
