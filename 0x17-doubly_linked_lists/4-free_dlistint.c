#include "lists.h"
/**
 * free_dlistint - frees a dlistint_t list.
 * @head: pointer to the head of the node
 * Return: nothing
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current, *temp;

	current = head;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}
