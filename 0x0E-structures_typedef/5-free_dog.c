#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - frees the memory allocated for a dog struct
 * @d: pointer to the dog struct to be freed
 */
void free_dog(dog_t *d)
{
if (d == NULL)
return;
/* Free the memory allocated for the name string */
if (d->name != NULL)
free(d->name);
/* Free the memory allocated for the owner string */
if (d->owner != NULL)
free(d->owner);
/* Free the memory allocated for the dog struct */
free(d);
}
