#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: A pointer to the first node of the linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tortoise, *hare;
	size_t count = 0;

	if (head == NULL)
		exit(98);
	tortoise = head;
	hare = head->next;
	while (hare != NULL && hare < tortoise)
	{
		count++;
		printf("[%p] %d\n", (void *)tortoise, tortoise->n);
		tortoise = tortoise->next;
		hare = hare->next;
		if (hare != NULL && hare < tortoise)
		{
			count++;
			printf("[%p] %d\n", (void *)tortoise, tortoise->n);
			tortoise = tortoise->next;
			hare = hare->next;
		}
	}
	if (hare != NULL)
	{
		count++;
		printf("[%p] %d\n", (void *)tortoise, tortoise->n);
		tortoise = tortoise->next;
	}
	while (hare != NULL && hare < tortoise)
	{
		count++;
		printf("[%p] %d\n", (void *)tortoise, tortoise->n);
		tortoise = tortoise->next;
		hare = hare->next;
	}
	if (hare != NULL)
	{
	count++;
	printf("-> [%p] %d\n", (void *)tortoise, tortoise->n);
	}
	return (count);
}
