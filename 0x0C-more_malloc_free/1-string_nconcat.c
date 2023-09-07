#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: maximum number of bytes of s2 to concatenate
 *
 * Return: pointer to newly allocated space in memory containing concatenated
 * strings or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
unsigned int len1 = 0, len2 = 0, i, j = 0;
char *new_str;
if (s1 == NULL)
s1 = "";
if (s2 == NULL)
s2 = "";
while (s1[len1] != '\0')
len1++;
while (s2[len2] != '\0')
len2++;
if (n >= len2)
n = len2;
new_str = malloc(len1 + n + 1);
if (new_str == NULL)
return (NULL);
for (i = 0; i < len1; i++)
new_str[j++] = s1[i];
for (i = 0; i < n; i++)
new_str[j++] = s2[i];
new_str[j] = '\0';
return (new_str);
}
