#include "main.h"

/**
 * leet - encodes a string into 1337
 * @str: string to encode
 *
 * Return: encoded string
 */
char *leet(char *str)
{
int i, j;
char letters[] = "aAeEoOtTlL";
char numbers[] = "43071";
for (i = 0; str[i]; i++)
{
for (j = 0; letters[j]; j++)
{
if (str[i] == letters[j])
{
str[i] = numbers[j / 2];
break;
}
}
}
return (str);
}
