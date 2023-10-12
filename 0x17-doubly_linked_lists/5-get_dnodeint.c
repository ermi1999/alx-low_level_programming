#include "lists.h"
/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list.
 * @head: pointer to the head of the list
 * @index: the index which the node will be returned
 * Return: the node if it exist or else NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *node;
	unsigned int i = 0;

	while (head != NULL)
	{
		if (i == index)
		{
			node = head;
			break;
		}
		else
		{
			head = head->next;
			i++;
		}
	}
	if (node == NULL)
	{
		return (NULL);
	}
	return (node);
}
