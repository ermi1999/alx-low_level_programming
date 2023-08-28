#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_nodeint - Adds a new node at the beginning of list_t list
 * @n: int to be duplicated and stored in the new node
 * Return: the address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
