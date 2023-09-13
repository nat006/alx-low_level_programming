#include <stdio.h>
#include "function_pointers.h"

/**
 * array_iterator - executes a given function on each element of an array.
 *
 * @array: a pointer to an integer array.
 * @size: the size of the array.
 * @action: pointer to the function to be executed on each element of array.
 * The function takes an integer argument and returns void.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
if (array == NULL || action == NULL)
return;
for (size_t i = 0; i < size; i++)
{
action(array[i]);
}
}
