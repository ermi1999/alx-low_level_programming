#include "search_algos.h"
/*
 * linear_search - implements a linear search searching algorithm.
 * @array: the array which the value to be searched in
 * @size: the size of the array.
 * @value: the value to search.
 * Return: The index.
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
