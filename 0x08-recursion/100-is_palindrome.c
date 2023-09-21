#include "main.h"
#include <string.h>

/**
 * is_palindrome_recursive - Recursive helper function to check if a string is a palindrome
 * @s: The string to check
 * @start: The starting index for comparison
 * @end: The ending index for comparison
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int is_palindrome_recursive(char *s, int start, int end)
{
	if (start >= end)
	{
		return (1); /* Base case: All characters have been compared */
	}

	if (s[start] != s[end])
	{
		return (0); /* Characters don't match, not a palindrome */
	}

	return (is_palindrome_recursive(s, start + 1, end - 1)); /* Compare next pair of characters */
}

/**
 * is_palindrome - Checks if a string is a palindrome
 * @s: The string to check
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int length = strlen(s);

	if (length <= 1)
	{
		return (1); /* An empty string or single character is a palindrome */
	}

	return (is_palindrome_recursive(s, 0, length - 1)); /* Compare characters recursively */
}
