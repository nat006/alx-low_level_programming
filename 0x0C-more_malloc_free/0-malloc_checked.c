#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * malloc_checked - allocate memory of size b
 * @b: size of allocation in bytes
 *
 * Return: pointer to allocated memory
 * Terminate with exit status 98 on failure
 */
void *malloc_checked(unsigned int b)
{
char *output;
output = malloc(b);
if (output == NULL)
exit(98);
else
return (output);
}
