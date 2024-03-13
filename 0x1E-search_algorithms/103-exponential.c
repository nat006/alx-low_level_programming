#include "search_algos.h"

/**
 * exponential_search -Search for val in sorted array using Expo search algo
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the value in the array or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
size_t idx = 1;
size_t low, high, mid, i;
if (array == NULL)
return (-1);
while (idx < size && array[idx] < value)
{
printf("Value checked array[%lu] = [%d]\n", idx, array[idx]);
idx *= 2;
}
low = idx / 2;
high = idx < size - 1 ? idx : size - 1;
printf("Value found between indexes [%lu] and [%lu]\n", low, high);
while (low <= high)
{
mid = (low + high) / 2;
printf("Searching in array: ");
for (i = low; i <= high; i++)
{
if (i == high)
printf("%d\n", array[i]);
else
printf("%d, ", array[i]);
}
if (array[mid] == value)
return (mid);
else if (array[mid] < value)
low = mid + 1;
else
high = mid - 1;
}
return (-1);
}
