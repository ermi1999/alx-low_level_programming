#include "main.h"

/**
 * is_prime_recursive - Recursive helper function to check if a number is prime
 * @n: The number to check
 * @divisor: The current divisor being tested
 *
 * Return: 1 if the number is prime, 0 otherwise
 */
int is_prime_recursive(int n, int divisor)
{
	if (n < 2 || n % divisor == 0)
	{
		return (0); /* Not a prime number */
	}

	if (divisor * divisor > n)
	{
		return (1); /* Found a prime number */
	}

	return (is_prime_recursive(n, divisor + 1)); /* Test the next divisor */
}

/**
 * is_prime_number - Checks if a number is a prime number
 * @n: The number to check
 *
 * Return: 1 if the number is prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}

	return (is_prime_recursive(n, 2));
}
