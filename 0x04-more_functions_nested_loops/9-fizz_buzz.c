#include <stdio.h>
/**
*main - prints numbers (1 to 100) in multiples of three
*Fizz is printed instead of the number, for multiples of five
*Buzz is printed for both three and five
*Return: 0
*/
int main(void)
{
int num;
for (num = 1; num <= 100; num++)
{
if ((num % 3) == 0 && (num % 5) == 0)
printf("FizzBuzz");
else if ((num % 3) == 0)
printf("Fizz");
else if ((num % 5) == 0)
printf("Buzz");
else
printf('%d', num);
if (num == 100)
continue;
printf(" ");
}
printf('/n');
return (0);
}
