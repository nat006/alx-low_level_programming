#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_list - Prints all the elements of a list_t list
 * @h: Head of the list
 *
 * Return: Number of nodes
 */
size_t print_list(const list_t *h)
{
size_t nodes = 0;
while (h != NULL)
{
if (h->str != NULL)
printf("[%u] %s\n", h->len, h->str);
else
printf("[0] (nil)\n");
nodes++;
h = h->next;
}
return (nodes);
}
