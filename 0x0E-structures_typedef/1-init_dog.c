#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - initializes a struct dog with given values
 * @d: pointer to the dog struct to be initialized
 * @name: pointer to the name of the dog (string)
 * @age: the age of the dog (float)
 * @owner: pointer to the name of the dog's owner (string)
 *
 * Return: None
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
if (d != NULL)
{
d->name = name;
d->age = age;
d->owner = owner;
}
}
