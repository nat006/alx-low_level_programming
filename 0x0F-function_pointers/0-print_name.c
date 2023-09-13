#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - prints a name.
 *
 * @name: a pointer to a string representing the name to print.
 * @f: a function pointer to a function that will be used to print the name.
 * The function takes a char pointer argument and returns void.
 */
void print_name(char *name, void (*f)(char *))
{
if (name == NULL || f == NULL)
return;
f(name);
}
