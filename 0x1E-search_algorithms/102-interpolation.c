#include "search_algos.h"
/**
 * interpolation_search - searchs a value using
 * Interpolation search algorithm.
 * @array: the array in which the value to search in.
 * @size: the size of the array.
 * @value: the value to search.
 * Return: the index of the value or -1.
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t high = size - 1;
	size_t pos;
	size_t low = 0;

	if (array == NULL)
		return (-1);

	pos = low + (
			((double)(high - low) / (array[high] - array[low])) * (value - array[low]));

	while ((
				array[low] < array[high]) && (
					array[low] <= value) && (
						value <= array[high]))
	{
		pos = low + ((
					(double)(high - low) / (array[high] - array[low])) * (
					value - array[low]));
		printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
		if (array[pos] < value)
			low = pos + 1;
		else if (value < array[pos])
			high = pos - 1;
		else
			return (pos);

	}

	printf("Value checked array[%ld] is out of range\n", pos);
	return (-1);
}
