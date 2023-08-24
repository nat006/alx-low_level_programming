#include "main.h"

/**
 * print_buffer - prints a buffer
 * @b: buffer to print
 * @size: number of bytes to print
 *
 * Return: void
 */
void print_buffer(char *b, int size)
{
int i, j;
char *hex_str = "0123456789abcdef";
if (size <= 0)
{
printf("\n");
return;
}
for (i = 0; i < size; i += 10)
{
printf("%08x: ", i);
for (j = 0; j < 10; j++)
{
if (i + j < size)
{
printf("%c%c ", hex_str[(b[i + j] >> 4) & 0xf],
hex_str[b[i + j] & 0xf]);
}
else
{
printf("   ");
}
}
for (j = 0; j < 10 && i + j < size; j++)
{
printf("%c", (b[i + j] >= ' ' && b[i + j] <= '~') ? b[i + j] : '.');
}
printf("\n");
}
}
