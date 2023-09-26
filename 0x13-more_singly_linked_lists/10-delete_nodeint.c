#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes node at index
 * index of a listint_t linked list.
 * @head: Pointer to first node of listint_t list
 * @index: Index of the node that should be deleted. Index starts at 0
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *temp = *head, *delete_node;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = temp->next;
		free(temp);
		return (1);
	}

	for (i = 0; temp != NULL && i < index - 1; i++)
		temp = temp->next;

	if (temp == NULL || temp->next == NULL)
		return (-1);

	delete_node = temp->next;
	temp->next = delete_node->next;
	free(delete_node);

	return (1);
}
