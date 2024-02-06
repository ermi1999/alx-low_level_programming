#include "search_algos.h"
/**
 * binary_search - implements a binary search searching algorithm.
 * @array: the array which the value to be searched in (sorted)
 * @size: the size of the array.
 * @value: the value to search.
 * Return: The index.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left;
	size_t right = size - 1;

	if (array == NULL)
		return (-1);
	while (left <= right)
	{
		size_t middle = left + (right - left) / 2;
		size_t i;

		printf("Searching in array: ");
		for (i = left; i <= right; i++)
		{
			if (i == right)
				printf("%d\n", array[i]);
			else
				printf("%d, ", array[i]);
		}
		if (array[middle] == value)
			return (middle);
		else if (array[middle] < value)
			left = middle + 1;
		else
			right = middle - 1;
	}
	return (-1);
}
