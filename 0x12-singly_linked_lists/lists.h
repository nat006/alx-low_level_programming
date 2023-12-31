#ifndef LINKED_H
#define LINKED_H

#include <stddef.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct list_s - Stringly linked list
 * @len: length of the string
 * @str: String.
 * @next: Points to the next node.
 * Description: Stringly linked list node structure.
 */
typedef struct list_s
{
char *str;
unsigned int len;
struct list_s *next;
} list_t;

size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);
void print_before_main(void);
#endif
