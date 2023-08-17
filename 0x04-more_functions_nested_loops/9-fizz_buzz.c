#include <stdio.h>
/**
*main - prints numbers (1 to 100) in multiples of three
*Return: 0
*/
int main(void)
{
int i;
for (i = 1; i <= 100; i++)
{
if ((i % 3 == 0) && (i % 5 == 0))
printf("%s", "FizzBuzz");
else if (i % 3 == 0)
printf("%s", "Fizz");
else if (i % 5 == 0)
printf("%s", "Buzz");
else
printf("%d", i);
}
printf("\n");
return (0);
}
