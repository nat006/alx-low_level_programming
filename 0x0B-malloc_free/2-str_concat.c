#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: first string to be concatenated
 * @s2: second string to be concatenated
 *
 * Return: If memory allocation fails, returns NULL.
 *         Otherwise, returns a pointer to the concatenated string.
 */
char *str_concat(char *s1, char *s2)
{
char *concat_str;
unsigned int i, j, len1, len2;
if (s1 == NULL)
s1 = "";
if (s2 == NULL)
s2 = "";
len1 = 0;
while (s1[len1])
len1++;
len2 = 0;
while (s2[len2])
len2++;
concat_str = malloc(sizeof(char) * (len1 + len2 + 1));
if (concat_str == NULL)
return (NULL);
for (i = 0; i < len1; i++)
concat_str[i] = s1[i];
for (j = 0; j <= len2; j++)
concat_str[i + j] = s2[j];
return (concat_str);
}
