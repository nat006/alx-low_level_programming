#include "main.h"
/**
 * print_binary - prints the binary representation of a number.
 * @n: unsigned long int value to convert to binary and print
 *
 * Return: void
 *
 * Description: You are not allowed to use arrays or the % or / operators.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int flag = 0;

	mask = mask << ((sizeof(unsigned long int) * 8) - 1);

	while (mask != 0)
	{
		if ((n & mask) == 0 && flag == 1)
			_putchar('0');
		else if ((n & mask) != 0)
		{
			_putchar('1');
			flag = 1;
		}

		mask = mask >> 1;
	}

	if (flag == 0)
		_putchar('0');
}
