#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *curr = head;
	size_t count = 0;

	while (curr != NULL)
	{
		printf("[%p] %d\n", (void *)curr, curr->n);
		count++;
		if (curr <= curr->next) /* Check for a loop */
		{
			printf("-> [%p] %d\n", (void *)curr->next, curr->next->n);
			exit(98);
		}
		curr = curr->next;
	}

	return (count);
}
