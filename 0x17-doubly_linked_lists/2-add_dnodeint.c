#include "lists.h"
/**
 * add_dnodeint - adds a new node at the beginning of a list
 * @head: pointer to pointer to the head of the node
 * @n: the value of the node
 * Return: the address of the new elementor NULL if failed so
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
	{
		return (NULL);
	}

	new->n = n;
	new->next = *head;
	new->prev = NULL;

	if (*head != NULL)
	{
		(*head)->prev = new;
	}
	*head = new;

	return (new);
}
