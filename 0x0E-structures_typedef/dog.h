#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a structure for representing a dog
 * @name: pointer to the name of the dog (string)
 * @age: the age of the dog (float)
 * @owner: pointer to the name of the dog's owner (string)
 *
 * Description: A structure that contains information about a dog,
 *              including its name, age, and the name of its owner.
 */
struct dog
{
char *name;
float age;
char *owner;
};


void init_dog(struct dog *d, char *name, float age, char *owner);
int _strlen(char *s);
void print_dog(struct dog *d);
typedef struct dog dog_t;
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
char *_strcpy(char *dest, char *src);

#endif
