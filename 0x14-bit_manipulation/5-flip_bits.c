#include "main.h"
/**
 * flip_bits - returns the number of bits you would need to flip to get
 * from one number to another.
 * @n: unsigned int value
 * @m: unsigned int value
 *
 * Return: The number of bits needed to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_res = n ^ m;
	unsigned int count = 0;

	while (xor_res)
	{
		count += xor_res & 1;
		xor_res >>= 1;
	}

	return (count);
}
