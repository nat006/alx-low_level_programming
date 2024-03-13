#include "search_algos.h"

/**
 * jump_list - Search for val in sorted list of ints using Jump search algo
 * @list: Pointer to the head of the list
 * @size: Number of nodes in the list
 * @value: Value to search for
 *
 * Return: Pointer to first node where value is located or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
listint_t *current, *prev;
size_t jump, i;
if (list == NULL)
return (NULL);
jump = sqrt(size);
current = list;
prev = NULL;
while (current->n < value)
{
prev = current;
for (i = 0; current->next != NULL && i < jump; i++)
current = current->next;
printf("Value checked at index [%lu] = [%d]\n", current->n, current->n);
if (i < jump)
break;
}
printf("Value found between indexes [%lu] and [%lu]\n", prev->n, current->n);
while (prev != NULL && prev->n <= current->n)
{
printf("Value checked at index [%lu] = [%d]\n", prev->n, prev->n);
if (prev->n == value)
return (prev);
prev = prev->next;
}
return (NULL);
}
