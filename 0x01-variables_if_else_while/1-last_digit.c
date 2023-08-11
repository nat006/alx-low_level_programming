#include <stdlib.h>

#include <time.h>

#include <stdio.h>

/**
 * main - Entry point
 * Return: 0 (Successful)
 */

int main(void)
{
int n, m;
srand(time(NULL));
n = rand() % 201 - 100;
m = n % 10;
if (m > 5)
printf("Last digit of %d  is %d and is greater than 5\n", n, m);
if (m == 0)
printf("Last digit of %d is %d and is 0\n", n, m);
if (m < 6 && m != 0)
printf("Last digit of %d is %d and is less than 6 and not 0\n", n, m);
return (0);
}
