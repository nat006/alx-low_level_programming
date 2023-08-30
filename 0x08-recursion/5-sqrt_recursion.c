#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number to find its square root
 *
 * Return: natural square root of n, -1 if n not natural square root
 */
int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);
if (n == 0 || n == 1)
return (n);
return (_sqrt_helper(n, 1));
}

/**
 * _sqrt_helper - helper function to find the natural square root
 * @n: the number to find its square root
 * @i: the possible square root
 *
 * Return: natural square root of n, -1 if n not have natural square root
 */
int _sqrt_helper(int n, int i)
{
if (i * i == n)
return (i);
if (i * i > n)
return (-1);
return (_sqrt_helper(n, i + 1));
}
