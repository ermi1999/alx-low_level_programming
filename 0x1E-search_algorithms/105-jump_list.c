#include "search_algos.h"
#include <math.h>

/**
 * jump_list - implements a jump search in a linked list.
 * @list: the list in which the value to be searched in.
 * @value: the value to search.
 * @size: the size of the list.
 * Return: the index of the value.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump, i, j = 0;
	listint_t *node = list;
	listint_t *prev;

	if (list == NULL)
		return (NULL);

	jump = sqrt(size);

	for (i = 0; i < size; i += jump)
	{
		prev = node;
		for (j = 0; node->next && j < jump; j++)
			node = node->next;
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
		if (node->n < value)
			continue;
		else
			break;
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			prev->index, node->index);

	for (i = 0; i < jump; i++)
	{
		printf("Value checked at index [%ld] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}
