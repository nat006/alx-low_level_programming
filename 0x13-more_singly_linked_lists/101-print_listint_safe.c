#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: A pointer to the node of the linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current;
	size_t node_count = 0;

	if (head == NULL)
		exit(98);

	current = head;

	while (current != NULL)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		node_count++;

		if (current >= current->next)
		{
			printf("-> [%p] %d\n", (void *)current->next,
				current->next->n);
			break;
		}

		current = current->next;
	}

	return (node_count);
}
