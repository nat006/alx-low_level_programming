#include "main.h"

int palindrome_helper(char *s, int start, int end);

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: the string to check
 *
 * Return: 1 if the string is a palindrome, otherwise return 0
 */
int is_palindrome(char *s)
{
int len = strlen(s);
return (palindrome_helper(s, 0, len - 1));
}

/**
 * palindrome_helper - helper function to check if a string is a palindrome
 * @s: the string to check
 * @start: the starting index
 * @end: the ending index
 *
 * Return: 1 if the string is a palindrome, otherwise return 0
 */
int palindrome_helper(char *s, int start, int end)
{
if (start >= end)
return (1);
if (s[start] != s[end])
return (0);
return (palindrome_helper(s, start + 1, end - 1));
}
