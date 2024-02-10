#include "search_algos.h"

/**
 * solve_recursively - implements a binary search recursively.
 * @array: the array in which the value to be searched in.
 * @left: the begining of the array.
 * @right: the end of the array.
 * @value: the value to be searched.
 * Return: the index.
 */
int solve_recursively(int *array, size_t left, size_t right, int value)
{
	size_t middle, i;

	if (left > right)
		return (-1);

	middle = left + (right - left) / 2;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		if (i != right)
			printf("%d, ", array[i]);
		else
			printf("%d\n", array[i]);
	}
	if (array[middle] == value)
	{
		if (middle == left || array[middle - 1] != value)
			return (middle);
	}
	if (array[middle] >= value)
		return (solve_recursively(array, left, middle, value));
	return (solve_recursively(array, middle + 1, right, value));
}


/**
 * advanced_binary - implements advanced binary search.
 * @array: the array which the value to be searched in (sorted)
 * @size: the size of the array.
 * @value: the value to search
 * Return: the index of the first value.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	return (solve_recursively(array, 0, size - 1, value));
}
