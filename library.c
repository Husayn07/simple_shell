#include "shell.h"

/**
 * _strcmp - Compare string values
 * @s1: First input string
 * @s2: Second input string
 * Return: 0 if equal, 1 if not equal
 */
int _strcmp(const char *s1, const char *s2)
{
        int i = 0;

        while (s1[i] != '\0' && s2[i] != '\0')
        {
                if (s1[i] != s2[i])
                {
                        return (1);
                }
                i++;
        }
        return (0);
}

/**
 * _strdup - Duplicate a string
 * @str: Input string
 * Return: Pointer to the new duplicated string
 */
char *_strdup(const char *str)
{
        char *dup;
        int i, len = 0;

        if (str == NULL)
                return (NULL);

        while (str[len] != '\0')
                len++;

        dup = malloc(sizeof(char) * (len + 1));

        if (dup == NULL)
                return (NULL);

        for (i = 0; str[i]; i++)
                dup[i] = str[i];

        return (dup);
}

/**
 * str_concat_ - Concatenate strings with separator
 * @s1: First input string
 * @s: Separator string
 * @s2: Second input string
 * Return: Pointer to the concatenated string
 */
char *str_concat_(const char *s1, const char *s, const char *s2)
{
        char *concat;
        int i, ci, len1 = 0, len2 = 0;

        if (s1 == NULL)
                s1 = "";
        if (s2 == NULL)
                s2 = "";

        while (s1[len1] != '\0')
                len1++;
        while (s2[len2] != '\0')
                len2++;

        concat = malloc(sizeof(char) * (len1 + len2 + 2));

        if (concat == NULL)
                return (NULL);

        i = ci = 0;
        while (s1[i] != '\0')
        {
                concat[i] = s1[i];
                i++;
        }
        concat[i] = s[0];
        i++;
        while (s2[ci] != '\0')
        {
                concat[i] = s2[ci];
                i++, ci++;
        }
        concat[i] = '\0';
        return (concat);
}

/**
 * _strchr - Check if a character matches any character in a string
 * @str: Input string
 * @character: Character to check
 * Return: Address if successful, NULL if failed
 */
char *_strchr(char *str, char character)
{
        while (*str != '\0')
        {
                if (*str == character)
                {
                        return (str);
                }
                str++;
        }
        return (NULL);
}
