#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list and returns
 *               the head node's data (n).
 * @head: Pointer to pointer to first node of listint_t list
 *
 * Return: The head node's data (n), 0 if linked list is empty.
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (head == NULL || *head == NULL)
		return (0);

	temp = *head;
	*head = (*head)->next;
	n = temp->n;
	free(temp);

	return (n);
}
