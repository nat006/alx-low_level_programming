#include "lists.h"
#include <stdlib.h>
/**
 * delete_dnodeint_at_index - deletes node at index of dlistint_t linked list
 * @head: double pointer to the head of the list
 * @index: index of the node that should be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head, *prev = NULL;
	unsigned int i = 0;

	if (current == NULL)
		return (-1);

	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	while (current != NULL && i < index)
	{
		prev = current;
		current = current->next;
		i++;
	}

	if (current == NULL)
		return (-1);

	prev->next = current->next;

	if (current->next != NULL)
		current->next->prev = prev;

	free(current);

	return (1);
}

