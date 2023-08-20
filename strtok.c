#include "shell.h"

/**
 * _strtok - string sepetaror.
 * @str: parameter
 * @delim: parameter
 * Return: address of strings
 */

char *_strtok(char *str, const char *delim)
{
	static char *n_tk;

	char *curr;

	if (str != NULL)
	{
		n_tk = str;
	}
	else if (n_tk == NULL)
	{
		return (NULL);
	}
	while (*n_tk != '\0' && _strchr(delim, *n_tk) != NULL)
	{
		n_tk++;
	}
	if (*n_tk == '\0')
	{
		n_tk = NULL;
		return (NULL);
	}
	curr = n_tk;
	while (*n_tk != '\0' && _strchr(delim, *n_tk) == NULL)
	{
		n_tk++;
	}
	if (*n_tk != '\0')
	{
		*n_tk = '\0';
		n_tk++;
	}
	else
	{
		n_tk = NULL;
	}
	return (curr);
}
