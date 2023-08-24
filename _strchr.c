#include "shell.h"

/**
 * _strchr - Locates a character in a string
 * @s: The string to search
 * @c: The character to find
 *
 * Return: A pointer to the first occurrence of the character,
 *         or NULL if the character is not found
 */
char *_strchr(const char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (char *)s;
		}
		s++;
	}
	return (NULL);
}
