#include "lists.h"
/**
 * insert_dnodeint_at_index - inserts a new node at given position
 * @h: pointer to pointer to the head of the node
 * @idx: the given position
 * @n: the number value to be added to the node
 * Return: the new node or NULL if it faild
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *node;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);
	if (idx == 0)
		return (add_dnodeint(h, n));
	node = *h;
	while (node != NULL && i < idx - 1)
	{
		node = node->next;
		i++;
	}
	if (node == NULL)
		return (NULL);
	if (node->next == NULL)
		return (add_dnodeint_end(h, n));
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = node->next;
	new->prev = node;
	node->next->prev = new;
	node->next = new;

	return (new);
}
