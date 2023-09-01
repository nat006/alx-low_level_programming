#include "main.h"

/**
 * _strchr - Locates a character in a string
 * @s: The string to search through
 * @c: The character to locate
 *
 * Return: 0
 */
char *_strchr(char *s, char c)
{
int a = 0;
for (; s[a] >= '\0'; a++)
{
if (s[a] == c)
return (&s[a]);
}
return (0);
}
