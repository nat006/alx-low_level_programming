#include "function_pointers.h"
#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - entry point for simple calculator program.
 *
 * @argc: number of command-line arguments.
 * @argv: array of command-line argument strings.
 *
 * Return: 0 on success, 98 on wrong number of arguments, 99 on
 * invalid operator, or 100 on division/modulo by zero.
 */
int main(int argc, char **argv)
{
int a, b, result;
int (*op_func)(int, int);
if (argc != 4)
{
printf("Error\n");
exit(98);
}
a = atoi(argv[1]);
b = atoi(argv[3]);
op_func = get_op_func(argv[2]);
if (!op_func)
{
printf("Error\n");
exit(99);
}
if ((*argv[2] == '/' || *argv[2] == '%') && b == 0)
{
printf("Error\n");
exit(100);
}
result = op_func(a, b);
printf("%d\n", result);
return (0);
}
