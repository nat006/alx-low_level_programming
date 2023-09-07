#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _isdigit - Check if a given character is a digit
 * @c: character to check
 *
 * Return: 1 if c is a digit, otherwise 0
 */
int _isdigit(char c)
{
return (c >= '0' && c <= '9');
}

/**
 * mul - Multiply two positive numbers
 * @num1: first number
 * @num2: second number
 *
 * Return: Pointer to the result string
 */
char *mul(char *num1, char *num2)
{
int len1 = 0, len2 = 0, i, j, carry = 0, sum;
char *result;
while (num1[len1])
len1++;
while (num2[len2])
len2++;
result = malloc(len1 + len2);
if (result == NULL)
return (NULL);
for (i = 0; i < len1 + len2; i++)
result[i] = '0';
for (i = len2 - 1; i >= 0; i--)
{
carry = 0;
for (j = len1 - 1; j >= 0; j--)
{
sum = (num2[i] - '0') * (num1[j] - '0') + carry + (result[i + j + 1] - '0');
carry = sum / 10;
result[i + j + 1] = sum % 10 + '0';
}
result[i + j + 1] += carry;
}
return (result);
}

/**
 * main - Program entry point
 * @argc: Number of command-line arguments
 * @argv: Array of pointers to argument strings
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
char *result;
if (argc != 3)
{
printf("Error\n");
return (98);
}
for (int i = 1; argv[i]; i++)
for (int j = 0; argv[i][j]; j++)
if (!_isdigit(argv[i][j]))
{
printf("Error\n");
return (98);
}
result = mul(argv[1], argv[2]);
if (result == NULL)
{
printf("Error\n");
return (98);
}
while (*result == '0' && *(result + 1) != '\0')
result++;
printf("%s\n", result);
free(result);
return (0);
}
