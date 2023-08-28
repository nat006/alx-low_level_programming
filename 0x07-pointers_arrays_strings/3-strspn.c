#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring
 * @s: The string to search through
 * @accept: The string of characters to search for
 *
 * Return: The number of bytes in the initial segment of s
 *         which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
unsigned int len = 0;
int i, j;
int found;
for (i = 0; s[i] != '\0'; i++)
{
found = 0;
for (j = 0; accept[j] != '\0'; j++)
{
if (s[i] == accept[j])
{
len++;
found = 1;
break;
}
}
if (found == 0)
{
return (len);
}
}
return (len);
}
