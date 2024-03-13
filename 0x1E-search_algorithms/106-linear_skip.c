#include "search_algos.h"
#include <stdio.h>

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: pointer to the first node where value is located,
 *         or NULL if value is not present or if head is NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *current, *express;
if (list == NULL)
return (NULL);
current = list;
express = list->express;
while (express)
{
printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
if (express->n >= value)
break;
current = express;
express = express->express;
}
printf("Val between index [%lu] and [%lu]\n", current->index, express->index);
while (current)
{
printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
if (current->n == value)
return (current);
if (current->n > value)
return (NULL);
current = current->next;
}
return (NULL);
}
