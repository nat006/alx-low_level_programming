#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * print_dog - prints the given dog struct to the console
 * @d: pointer to the dog struct to be printed
 *
 * Return: None
 */
void print_dog(struct dog *d)
{
if (d == NULL)
return;
printf("Name: %s\n", (d->name != NULL) ? d->name : "(nil)");
printf("Age: %.6f\n", d->age);
printf("Owner: %s\n", (d->owner != NULL) ? d->owner : "(nil)");
}
