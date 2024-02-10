#include "search_algos.h"

/**
 * linear_skip - implments a searching algorithm in linear_skip linked list.
 * @list: the list in which the value to be searched in.
 * @value: the value to be searched.
 * Return: a pointer to the value.
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev, *temp;
	size_t i;

	if (list == NULL)
		return (NULL);

	while (list != NULL)
	{
		prev = list;
		list = list->express;
		if (list != NULL)
		{
			i = list->index;
			printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
			if (list->n < value)
				continue;
			else
				break;
		}
	}
	if (list == NULL)
	{
		temp = prev;
		while (temp != NULL)
		{
			if (temp->next != NULL)
				i++;
			temp = temp->next;
		}
	}
	printf("Value found between indexes [%ld] and [%ld]\n", prev->index, i);
	while (prev != NULL)
	{
		printf("Value checked at index [%ld] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}
