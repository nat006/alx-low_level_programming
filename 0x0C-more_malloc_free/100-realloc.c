#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory block previously allocated
 * @old_size: the size in bytes of the allocated space for ptr
 * @new_size: the new size in bytes of the new memory block
 *
 * Return: Pointer to the newly allocated memory block, or NULL on failure
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
{
char *new_ptr;
char *old_ptr;
unsigned int i;
if (new_size == old_size)
return (ptr);
if (ptr == NULL)
return (malloc(new_size));
if (new_size == 0)
{
free(ptr);
return (NULL);
}
new_ptr = malloc(new_size);
if (new_ptr == NULL)
return (NULL);
old_ptr = ptr;
if (new_size > old_size)
for (i = 0; i < old_size; i++)
new_ptr[i] = old_ptr[i];
else
for (i = 0; i < new_size; i++)
new_ptr[i] = old_ptr[i];
free(ptr);
return ((void *)new_ptr);
}
