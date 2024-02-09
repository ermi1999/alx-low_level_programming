#include "search_algos.h"

/**
 * binarySearch - search for a value using a binary searching algorithm.
 * @array: the array in which the value to search for.
 * @value: the value to search for.
 * @start: the begining of the search.
 * @end: the end of the search.
 * Return: the index.
 */
int binarySearch(int *array, int value, size_t start, size_t end)
{
	if (array == NULL)
		return (-1);
	while (start <= end)
	{
		size_t middle = start + (end - start) / 2;
		size_t i;

		printf("Searching in array: ");
		for (i = start; i <= end; i++)
		{
			printf("%d", array[i]);
			if (i != end)
				printf(", ");
		}
		printf("\n");
		if (array[middle] == value)
			return (middle);
		else if (array[middle] < value)
			start = middle + 1;
		else
			end = middle - 1;
	}
	return (-1);
}

/**
 * exponential_search - searchs for a value using
 * exponential searching algorithm.
 * @array: the array in which the value to search for.
 * @size: the size of the array.
 * @value: the value to search for.
 * Return: the index of the value.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;
	size_t start, end;

	if (array == NULL)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	start = bound / 2;
	end = (bound < size) ? bound : size - 1;

	printf("Value found between indexes [%ld] and [%ld]\n", start, end);

	return (binarySearch(array, value, start, end));
}
