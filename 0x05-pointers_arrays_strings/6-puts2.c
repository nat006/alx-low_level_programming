#include "main.h"
/**
*puts2 - function that prints every other character of a string
*starting with the first char
*followed by a new line
*@str: input
*Return: print
*/
void puts2(char *str)
{
int longi = 0;
int t = 0;
char *y = str;
int b;
while (*y != '\0')
{
y++;
longi++;
}
t = longi - 1;
for (b = 0; b <= t; b++)
{
if (b % 2 == 0)
{
_putchar(str[b]);
}
}
_putchar('\n');
}
