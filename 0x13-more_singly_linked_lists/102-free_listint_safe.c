#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: Double pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current = *h;
	listint_t *next;
	size_t count = 0;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		count++;
		if (current <= next) /* Check for a loop */
		{
			*h = NULL;
			break;
		}
		current = next;
	}

	return (count);
}
