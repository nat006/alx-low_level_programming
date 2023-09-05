#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array and initializes it with a char
 * @size: the size of the array
 * @c: the char to initialize the array with
 *
 * Return: If size = 0 or if memory allocation fails, returns NULL.
 *         Otherwise, returns a pointer to the new array.
 */
char *create_array(unsigned int size, char c)
{
char *array;
unsigned int i;
if (size == 0)
return (NULL);
array = malloc(sizeof(char) * size);
if (array == NULL)
return (NULL);
for (i = 0; i < size; i++)
array[i] = c;
return (array);
}
