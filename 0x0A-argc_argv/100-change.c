#include <stdio.h>
#include <stdlib.h>

/**
 * main - calculates the minimum number of coins needed to make change
 * for an amount of money
 * @argc: number of arguments passed
 * @argv: array of arguments passed
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
int n, coins = 0;
if (argc != 2)
{
printf("Error\n");
return (1);
}
n = atoi(argv[1]);
if (n < 0)
{
printf("0\n");
return (0);
}
while (n >= 25)
{
coins++;
n -= 25;
}
while (n >= 10)
{
coins++;
n -= 10;
}
while (n >= 5)
{
coins++;
n -= 5;
}
while (n >= 2)
{
coins++;
n -= 2;
}
while (n >= 1)
{
coins++;
n -= 1;
}
printf("%d\n", coins);
return (0);
}
