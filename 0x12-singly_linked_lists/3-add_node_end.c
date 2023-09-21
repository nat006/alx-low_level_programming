#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - Adds a new node at the end of a list_t list
 * @head: Pointer to a pointer to the head node
 * @str: String value for the new node
 *
 * Return: Address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
char *str_copy = NULL;
list_t *new_node = NULL;
list_t *last_node = *head;
if (str == NULL)
return (NULL);
new_node = malloc(sizeof(list_t));
if (new_node == NULL)
return (NULL);
str_copy = strdup(str);
if (str_copy == NULL)
{
free(new_node);
return (NULL);
}
new_node->str = str_copy;
new_node->len = strlen(str_copy);
new_node->next = NULL;
if (*head == NULL)
*head = new_node;
else
{
while (last_node->next != NULL)
last_node = last_node->next;
last_node->next = new_node;
}
return (new_node);
}
