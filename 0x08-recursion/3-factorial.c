#include "main.h"

/**
 * factorial - returns the factorial of a given number
 * @n: the number to calculate its factorial
 *
 * Return: factorial of n, -1 on error
 */
int factorial(int n)
{
if (n < 0)
return (-1);
if (n == 0)
return (1);
return (n * factorial(n - 1));
}
