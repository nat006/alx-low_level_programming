#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: Pointer to first node of listint_t list
 * @index: Index of the node, starting at 0
 *
 * Return: The nth node of listint_t linked list, NULL if node does not exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	for (i = 0; head != NULL && i < index; i++)
		head = head->next;

	return (head == NULL || i != index ? NULL : head);
}
