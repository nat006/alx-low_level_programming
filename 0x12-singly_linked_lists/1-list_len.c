#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * list_len - Returns the number of elements in a linked list_t list
 * @h: Head of the list
 *
 * Return: Number of nodes
 */
size_t list_len(const list_t *h)
{
size_t nodes = 0;
while (h != NULL)
{
nodes++;
h = h->next;
}
return (nodes);
}
