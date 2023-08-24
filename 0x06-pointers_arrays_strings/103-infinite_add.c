#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer to store result
 * @size_r: buffer size
 *
 * Return: pointer to result
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
int i, j, sum, carry = 0;
for (i = 0, j = 0; n1[i] || n2[j]; i++, j++)
{
sum = carry;
if (n1[i])
{
sum += n1[i] - '0';
}
if (n2[j])
{
sum += n2[j] - '0';
}
if (i + 1 >= size_r || j + 1 >= size_r || sum >= 10)
{
return (0);
}
r[i] = sum % 10 + '0';
carry = sum / 10;
}
if (carry && i + 1 < size_r && j + 1 < size_r)
{
r[i] = carry + '0';
r[i + 1] = '\0';
}
else
{
return (0);
}
return (r);
}
