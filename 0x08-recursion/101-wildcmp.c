#include "main.h"

/**
 * wildcmp - Compares two strings with support for wildcard pattern matching
 * @s1: The first string
 * @s2: The second string (may contain wildcards: '*' and/or '?')
 *
 * Return: 1 if the strings match, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '\0')
			return (1); /* Matched the end of s2 */

		if (*s1 != '\0' && wildcmp(s1 + 1, s2))
			return (1); /* Matched the current character in s1 with '*' in s2 */

		return (wildcmp(s1, s2 + 1)); /* Skip '*' in s2 and continue matching */
	}

	if (*s1 == '\0')
		return ((*s2 == '\0'));

	if (*s1 == *s2 || *s2 == '?')
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
