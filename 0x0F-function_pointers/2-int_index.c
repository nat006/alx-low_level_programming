#include "function_pointers.h"

/**
 * int_index - searches for an integer in an array using a comparison function.
 *
 * @array: a pointer to an integer array.
 * @size: the number of elements in the array.
 * @cmp: a pointer to the comparison function. The function takes an integer
 * argument and returns an integer result.
 *
 * Return: index of the first element which the comparison function does not
 * return 0, or -1 if no such element is found or size <= 0.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
int i;
if (array == NULL || cmp == NULL || size <= 0)
return (-1);
for (i = 0; i < size; i++)
{
if (cmp(array[i]) != 0)
return (i);
}
return (-1);
}
