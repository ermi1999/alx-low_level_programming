#include "search_algos.h"
#include <math.h>

/**
 * jump_search - implements a jump search algorithm.
 * @array: the array.
 * @size: the size of the array.
 * @value: the value to search.
 * Return: the index of the value.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump = 0;
	size_t i, j = 0;

	if (array == NULL)
		return (-1);
	jump = sqrt(size);
	for (i = 0; i < size; i += jump)
	{
		if (array[i] < value)
		{
			printf("Value checked array[%lu] = [%d]\n", i, array[i]);
			continue;
		}
		else
			break;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", i - jump, i);
	for (j = i - jump; j < size; j++)
	{
		if (j > size - 1)
			return (-1);
		printf("Value checked array[%lu] = [%d]\n", j, array[j]);
		if (array[j] == value)
			return (j);
	}
	return (-1);
}
