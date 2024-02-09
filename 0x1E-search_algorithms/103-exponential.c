#include "search_algos.h"

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
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;

	if (array == NULL)
		return (-1);

	while (bound < size && array[bound] < value)
		bound *= bound;

	return binarySearch(array, value, bound / 2, (bound + 1 > size ? size : bound + 1));
}
