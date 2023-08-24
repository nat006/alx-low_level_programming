#include "main.h"
#include <stdio.h>

/**
 * rot13 - encodes a string using rot13
 * @str: string to encode
 *
 * Return: encoded string
 */
char *rot13(char *str)
{
int i, j;
char *alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char *rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
for (i = 0; str[i]; i++)
{
for (j = 0; alphabets[j]; j++)
{
if (str[i] == alphabets[j])
{
str[i] = rot13[j];
break;
}
}
}
return (str);
}
