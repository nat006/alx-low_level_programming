#include "main.h"
#include <unistd.h>

/**
*print_alphabet - Program that prints alphabet
*Return: 0 (success)
*/
void print_alphabet(void)
{
char c = 'a';
while (c <= 'z')
{
_putchar(c);
c++;
}
_putchar('\n');
}
