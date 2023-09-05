#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - creates a duplicate of a given string
 * @str: the string to be duplicated
 *
 * Return: If str is NULL or if memory allocation fails, returns NULL.
 *         Otherwise, returns a pointer to the new string.
 */
char *_strdup(char *str)
{
char *dup_str;
unsigned int i, len;
if (str == NULL)
return (NULL);
len = 0;
while (str[len])
len++;
dup_str = malloc(sizeof(char) * (len + 1));
if (dup_str == NULL)
return (NULL);
for (i = 0; i <= len; i++)
dup_str[i] = str[i];
return (dup_str);
}
