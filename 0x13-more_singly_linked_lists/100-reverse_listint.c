#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: A pointer to the pointer of the first node of the linked list.
 *
 * Return: A pointer to the first node of the reverse list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev_node = NULL, *next_node = NULL;

	if (*head == NULL)
		return (NULL);
	while ((*head)->next != NULL)
	{
		next_node = (*head)->next;
		(*head)->next = prev_node;
		prev_node = *head;
		*head = next_node;
	}

	(*head)->next = prev_node;

	return (*head);
}
