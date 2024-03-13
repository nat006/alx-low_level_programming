#include "search_algos.h"

/**
 * advanced_binary_recursive -Search val in sorted array using Bin search alg
 * @array: Pointer to the first element of the array
 * @low: The starting index of the subarray
 * @high: The ending index of the subarray
 * @value: Value to search for
 *
 * Return: Index of the value in the array or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t low, size_t high, int value)
{
size_t mid, i;
if (low <= high)
{
printf("Searching in array: ");
for (i = low; i < high; i++)
printf("%d, ", array[i]);
printf("%d\n", array[i]);
mid = low + (high - low) / 2;
if (array[mid] == value)
{
if (mid == low || array[mid - 1] != value)
return (mid);
else
return (advanced_binary_recursive(array, low, mid, value));
}
if (array[mid] < value)
return (advanced_binary_recursive(array, mid + 1, high, value));
else
return (advanced_binary_recursive(array, low, mid - 1, value));
}
return (-1);
}

/**
 * advanced_binary -Calls recursive func for val in array using Bin search alg
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the value in the array or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
if (array == NULL)
return (-1);
return (advanced_binary_recursive(array, 0, size - 1, value));
}
