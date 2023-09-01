#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - Adds positive numbers and prints the result
 * @argc: Number of arguments passed
 * @argv: Array of arguments passed
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
int sum = 0, i, j;
if (argc == 1)
{
printf("0\n");
return (0);
}
for (i = 1; i < argc; i++)
{
for (j = 0; argv[i][j] != '\0'; j++)
{
if (!isdigit(argv[i][j]))
{
printf("Error\n");
return (1);
}
}
if (atoi(argv[i]) > 0)
{
sum += atoi(argv[i]);
}
}
printf("%d\n", sum);
return (0);
}
