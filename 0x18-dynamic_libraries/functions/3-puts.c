#include "main.h"
/**
*_puts - function that that prints a string, followed by a new line, to stdout
*@str: string
*Return: length
*/
void _puts(char *str)
{
while (*str != '\0')
{
_putchar(*str++);
}
_putchar('\n');
}
