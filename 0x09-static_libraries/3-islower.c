#include "main.h"

/**
*_islower - Program that checks for lowercase alphabet
*@c: Character to be checked
*Return: 0 (success)
*/

int _islower(int c)
{
if (c >= 'a' && c <= 'z')
return (1);
else
return (0);
}
