#include "lists.h"
#include <stdlib.h>

/**
 * free_list - Frees a list_t list.
 * @head: Pointer to the head node
 *
 * Return: void
 */
void free_list(list_t *head)
{
list_t *current_node = NULL;
list_t *next_node = NULL;
current_node = head;
while (current_node != NULL)
{
next_node = current_node->next;
free(current_node->str);
free(current_node);
current_node = next_node;
}
}
