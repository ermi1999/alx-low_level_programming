#include "lists.h"
/**
 * sum_dlistint - calculates the sum of all doubly linked list
 * @head - pointer to the head of the node
 * Return: the sum of the linked list if the list if empty 0
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	if (head == NULL)
		return (0);
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
