#include <stdio.h>
#include "function_pointers.h"

/**
 * array_iterator - executes a given function on each element of an array.
 *
 * @array: a pointer to an integer array.
 * @size: the size of the array.
 * @action: pointer to the function to be executed on each element of the array
 * The function takes an integer argument and returns void.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
unsigned int i;
if (array == NULL || action == NULL)
return;
for (i = 0; i < size; i++)
{
action(array[i]);
}
}
