#include "main.h"

/**
 * _strpbrk - Searches a string for any of a set of bytes
 * @s: The string to search through
 * @accept: The string of bytes to search for
 *
 * Return: 0
 */
char *_strpbrk(char *s, char *accept)
{
int b;
while (*s)
{
for (b = 0; accept[b]; b++)
{
if (*s == accept[b])
return (s);
}
s++;
}
return ('\0');
}
