#include "main.h"
/**
 * set_bit - sets the value of a bit to 1 at a given index.
 * @n: pointer to ull value
 * @index: index, starting from 0 of the bit you want to set
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 *
 * Description: Where an error occured, the function fails silently.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int size = sizeof(unsigned long int) * 8;

	if (index >= size)
		return (-1);

	*n = (*n | (1 << index));

	return (1);
}
