#include "main.h"

int prime_helper(int n, int i);

/**
 * is_prime_number - checks if a number is prime
 * @n: the number to check
 *
 * Return: 1 if the number is prime, otherwise return 0
 */
int is_prime_number(int n)
{
if (n <= 1)
return (0);
return (prime_helper(n, 2));
}

/**
 * prime_helper - helper function to check if a number is prime
 * @n: the number to check
 * @i: the possible factor
 *
 * Return: 1 if the number is prime, otherwise return 0
 */
int prime_helper(int n, int i)
{
if (i == n)
return (1);
if (n % i == 0)
return (0);
return (prime_helper(n, i + 1));
}
