#include "search_algos.h"
#include <math.h>

/**
 * jump_search - searches for a value in a sorted array of integers
 * using the Jump search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return: the first index where value is located or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
size_t step, prev, start;
size_t i;
if (array == NULL)
return (-1);
step = sqrt(size);
prev = 0;
while (prev < size && array[prev] < value)
{
printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
prev += step;
}
start = prev - step;
printf("Value found between indexes [%lu] and [%lu]\n", start, prev);
for (i = start; i < size && i <= prev; i++)
{
printf("Value checked array[%lu] = [%d]\n", i, array[i]);
if (array[i] == value)
return (i);
}
return (-1);
}
