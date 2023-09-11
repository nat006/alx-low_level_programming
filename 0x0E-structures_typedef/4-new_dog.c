#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - creates new struct & initializes its variables with given values
 * @name: pointer to null-terminated string that represents the name of the dog
 * @age: float that represents the age of the dog
 * @owner: pointer to null-terminated string that reps the owner of the dog
 *
 * Return: pointer to the newly created struct, or NULL if memory alloc fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *new_dog = malloc(sizeof(dog_t));
if (new_dog == NULL)
return (NULL);
new_dog->name = malloc(strlen(name) + 1);
if (new_dog->name == NULL)
{
free(new_dog);
return (NULL);
}
strcpy(new_dog->name, name);
new_dog->owner = malloc(strlen(owner) + 1);
if (new_dog->owner == NULL)
{
free(new_dog->name);
free(new_dog);
return (NULL);
}
strcpy(new_dog->owner, owner);
/* Assign the age to the new dog */
new_dog->age = age;
/* Return a pointer to the new dog struct */
return (new_dog);
}
