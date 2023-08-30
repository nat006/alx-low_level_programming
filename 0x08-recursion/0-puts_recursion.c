#include "main.h"

/**
 * _puts_recursion - prints a string plus a new line to stdout
 * @s: pointer to the string to be printed
 *
 * Return: void
 */
void _puts_recursion(char *s)
{
if (*s == '\0')
{
_putchar('\n');
return;
}
_putchar(*s);
_puts_recursion(s + 1);
}
