#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * array_range - create an array of integers from min to max (inclusive)
 * @min: minimum value in the array
 * @max: maximum value in the array
 *
 * Return: pointer to the newly created array or NULL on failure
 */
int *array_range(int min, int max)
{
int *arr;
int i, size;
if (min > max)
return (NULL);
size = max - min + 1;
arr = malloc(sizeof(int) * size);
if (arr == NULL)
return (NULL);
for (i = 0; i < size; i++)
arr[i] = min++;
return (arr);
}
