#include "main.h"
#include <unistd.h>
/**
 * _putchar - writes the character c.
 * @c: the placeholder for the character to be printed
 *
 * Return: if it is success returns 1
 * On error, if it is an error it will return -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

