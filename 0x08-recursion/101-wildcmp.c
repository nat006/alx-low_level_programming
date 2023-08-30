#include "main.h"

/**
 * wildcmp - compare two strings and checks if they're identical
 * @s1: the first string
 * @s2: the second string
 *
 * Return: 1 if the strings are identical, otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
if (*s1 == '\0' && *s2 == '\0')
return (1);
if (*s2 == '*')
return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
if (*s1 != *s2)
return (0);
return (wildcmp(s1 + 1, s2 + 1));
}
