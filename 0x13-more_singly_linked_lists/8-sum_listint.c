#include "lists.h"

/**
 * sum_listint - Returns sum of all the data (n) of a listint_t linked list.
 * @head: Pointer to first node of listint_t list
 *
 * Return: The sum of all data (n) of listint_t linked list, 0 if list empty.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
