#include <stdio.h>

/**
 * main - Prints the number of arguments passed into the program
 * @argc: Number of arguments passed
 * @argv: Array of arguments passed
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
(void) argv;
printf("%d\n", argc - 1);
return (0);
}
