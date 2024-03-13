#include "search_algos.h"
#include <math.h>
/**
 * jump_list - Searches for a value in a sorted linked list using jump search
 * @list: Pointer to the head of the linked list
 * @size: Number of nodes in the list
 * @value: Value to search for
 * Return: Pointer to the node containing the value or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
int jump, i;
listint_t *current, *prev;
if (list == NULL || size == 0)
return (NULL);
jump = (int)sqrt(size);
current = list;
prev = NULL;
while (current->next && current->n < value)
{
prev = current;
for (i = 0; current->next && i < jump; i++)
{
current = current->next;
}
printf("Value checked [%lu] = [%d]\n", (unsigned long)current->n, current->n);
}
printf("Value found between [%lu] and [%lu]\n", (unsigned long)prev->n, (unsigned long)current->n);
printf("Value checked [%lu] = [%d]\n", (unsigned long)prev->n, prev->n);
while (prev && prev->n < value)
{
printf("Value checked at index [%lu] = [%d]\n", (unsigned long)prev->n, prev->n);
if (prev->next)
prev = prev->next;
else
return (NULL);
}
if (prev->n == value)
{
printf("Value checked at index [%lu] = [%d]\n", (unsigned long)prev->n, prev->n);
return (prev);
}
return (NULL);
}
