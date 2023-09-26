#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: A pointer to the pointer to the first node of the linked list.
 *
 * Return: The size of the list that was free'd.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *tmp, *current = *h;

	while (current != NULL && current > current->next)
	{
		tmp = current;
		current = current->next;
		free(tmp);
		count++;
	}

	if (current != NULL)
	{
		count++;
		free(current);
		current = NULL;
	}

	*h = NULL;

	return (count);
}
