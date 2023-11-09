#include "lists.h"
#include <stdlib.h>
/**
 * free_dlistint - frees a dlistint_t list
 * @head: pointer to the head of the list
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current = head;

	while (current != NULL)
	{
		head = head->next;
		free(current);
		current = head;
	}
}
