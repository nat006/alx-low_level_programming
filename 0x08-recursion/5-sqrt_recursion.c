#include "main.h"

/**
 * _sqrt_recursion - Computes the natural square root of a number.
 * @n: The number to find the square root of.
 *
 * Return: The natural square root of n, or -1 if n does not have a
 *         natural square root.
 */
int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);
if (n == 0 || n == 1)
return (n);
int start = 1;
int end = n;
int mid;
int sqrt;
while (start <= end)
{
mid = (start + end) / 2;
sqrt = n / mid;
if (mid == sqrt)
return (mid);
if (mid < sqrt)
start = mid + 1;
else
end = mid - 1;
}
return (end);
}
