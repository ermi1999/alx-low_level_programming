#include "main.h"

/**
 * sqrt_recursive - Recursive helper function to find the square root
 * @n: The number to find the square root of
 * @start: The starting point for the search
 * @end: The ending point for the search
 *
 * Return: The square root of the number,
 *         or -1 if the number does not have a natural square root
 */
int sqrt_recursive(int n, int start, int end)
{
	if (start > end)
	{
		return (-1); /* The number does not have a natural square root */
	}

	int mid = (start + end) / 2;
	int square = mid * mid;

	if (square == n)
	{
		return (mid); /* Found the square root */
	}

	if (square > n)
	{
		return (sqrt_recursive(n, start, mid - 1)); /* Search in the lower half */
	}

	return (sqrt_recursive(n, mid + 1, end)); /* Search in the upper half */
}

/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: The number to find the square root of
 *
 * Return: The square root of the number,
 *         or -1 if the number does not have a natural square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}

	return (sqrt_recursive(n, 0, n));
}
