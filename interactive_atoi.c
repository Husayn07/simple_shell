#include "shell.h"

/**
 * is_interactive_mode - Checks if the shell is in interactive mode.
 * @info: Pointer to an info_t structure.
 * Return: 1 if the shell is in interactive mode, 0 otherwise.
 */
int is_interactive_mode(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_character_delimiter - Checks if a character is a delimiter.
 * @c: The character to check.
 * @delim: The delimiter string.
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */
int is_character_delimiter(char c, char *delim)
{
	while (*delim)
	{
		if (*delim == c)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * is_alphabetic_character - Checks if a character is alphabetic.
 * @c: The character to check.
 * Return: 1 if the character is alphabetic, 0 otherwise.
 */
int is_alphabetic_character(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * string_to_integer - Converts a string to an integer.
 * @s: The string to be converted.
 * Return: The converted integer. If no numbers in string, returns 0.
 */
int string_to_integer(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result = result * 10 + (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	output = (sign == -1) ? -result : result;
	return (output);
}
