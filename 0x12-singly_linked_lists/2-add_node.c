#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add_node - Adds a new node at the beginning of a list_t list
 * @head: Pointer to a pointer to the head node
 * @str: String value for the new node
 *
 * Return: Address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
char *str_copy = NULL;
list_t *new_node = NULL;
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
new_node->next = *head;
*head = new_node;
return (new_node);
}
