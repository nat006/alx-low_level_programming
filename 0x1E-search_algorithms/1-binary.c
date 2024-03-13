#include "search_algos.h"
#include <stddef.h>
/**
 * binary_search -search for val in sorted array ints using Binary search algo
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: the value to search for
 * Return: index where value is located, or -1 if not found or array is NULL
 */
int binary_search(int *array, size_t size, int value)
{
size_t left = 0, right = size - 1;
size_t i;
if (array == NULL)
return (-1);
while (left <= right)
{
size_t mid = left + (right - left) / 2;
printf("Searching in array: ");
for (i = left; i <= right; i++)
{
printf("%d", array[i]);
if (i < right)
printf(", ");
else
printf("\n");
}
if (array[mid] == value)
return (mid);
else if (array[mid] < value)
left = mid + 1;
else
right = mid - 1;
}
return (-1);
}
