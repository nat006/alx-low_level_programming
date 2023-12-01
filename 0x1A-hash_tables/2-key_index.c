#include "hash_tables.h"

/**
 * key_index - Returns the index of a key in the hash table's array
 * @key: The key
 * @size: The size of the array
 *
 * Return: The index at which the key should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
unsigned long int hash_val = hash_djb2(key);
return (hash_val % size);
}
