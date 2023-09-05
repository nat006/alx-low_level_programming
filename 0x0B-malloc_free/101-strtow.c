#include "main.h"
#include <stdlib.h>

/**
 * count_words - count the number of words in a string
 * @str: string to count words in
 *
 * Return: the number of words in str
 */
int count_words(char *str)
{
int i, count = 0;
for (i = 0; str[i]; i++)
{
if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
count++;
}
return (count);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: If str is NULL or "" or if memory allocation fails, returns NULL.
 *         Otherwise, returns a pointer to a newly-allocated array of strings
 *         (words) terminated by a NULL pointer.
 */
char **strtow(char *str)
{
char **words;
int i, j, k;
int len = 0, word_count = 0;
if (str == NULL || str[0] == '\0')
return (NULL);
word_count = count_words(str);
words = malloc(sizeof(char *) * (word_count + 1));
if (words == NULL)
return (NULL);
for (i = 0; i < word_count; i++)
{
while (str[len] == ' ')
len++;
for (j = len; str[j] != ' ' && str[j] != '\0'; j++)
;
words[i] = malloc(sizeof(char) * (j - len + 1));
if (words[i] == NULL)
{
for (k = 0; k < i; k++)
free(words[k]);
free(words);
return (NULL);
}
for (k = 0; k < (j - len); k++)
words[i][k] = str[len + k];
words[i][k] = '\0';
len = j;
}
words[i] = NULL;
return (words);
}
