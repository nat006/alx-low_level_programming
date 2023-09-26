#include "lists.h"
#include <stdio.h>

/**
* print_listint - Prints all elements of a listint_t list
* @h: Pointer to head of listint_t list
*
* Return: The number of nodes
*/

size_t print_listint(const listint_t *h)
{
size_t count = 0;
while (h != NULL)
{
printf("%d\n", h->n);
count++;
h = h->next;
}
return (count);
}
