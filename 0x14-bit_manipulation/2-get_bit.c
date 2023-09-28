#include "main.h"
/**
 * get_bit - returns the value of a bit at a given index.
 * @n: unsigned long int value
 * @index: index, starting from 0 of the bit you want to get
 *
 * Return: the value of the bit at index index or -1 if an error occured.
 *
 * Description: Where an error occured, the function fails silently.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int size = sizeof(unsigned long int) * 8;

	if (index >= size)
		return (-1);

	return ((n >> index) & 1);
}
