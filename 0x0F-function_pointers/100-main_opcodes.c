#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function.
 *
 * @argc: the number of arguments passed to the program.
 * @argv: an array of pointers to the arguments.
 *
 * Return: 0 on success, 1 if the number of arguments is incorrect, or 2 if
 * the number of bytes is negative.
 */
int main(int argc, char **argv)
{
char *main_addr = (char *)main;
int num_bytes;
if (argc != 2)
{
printf("Error\n");
return (1);
}
num_bytes = atoi(argv[1]);
if (num_bytes < 0)
{
printf("Error\n");
return (2);
}
for (int i = 0; i < num_bytes; i++)
{
printf("%02hhx", main_addr[i]);
}
printf("\n");
return (0);
}
