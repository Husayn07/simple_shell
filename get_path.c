#include "shell.h"
#include <sys/stat.h>
#include <sys/types.h>



/**
 * get_path - a function that locate the path to a file in the environ.
 * @argv: vector array pointer to strings
 * @comand: parameter.
 * Return: 1 on sucess | 0 on faliure
 */

int get_path(char *argv, char **comand)
{
	char *ptr = NULL;
	char *tok = NULL;
	int check = 0;

	*comand = NULL;
	ptr = _getenv("PATH");
	char *ptr1 = _strdup(ptr);

	tok = _strtok(ptr1, ":");
	while (tok)
	{
		*comand = str_concat_(tok, "/", argv);
		check = stat_check_cat(*comand);
		if (check == 1)
		{
			free(ptr1);
			return (1);
		}
		tok = _strtok(NULL, ":");
	}
	free(ptr1);
	return (0);
}



/**
 * _getenv - a function that pull out path from envp.
 * @path_name: key name to be search for in envp[].
 * Return: NULL.
 */
char *_getenv(char *path_name)
{
	char **env_cur, *env_ptr, *nptr;

	env_cur = environ;
	while (*env_cur)
	{
		env_ptr = *env_cur;
		nptr = path_name;
		while (*env_ptr == *nptr)
		{
			if (*env_ptr == '=')
				break;
			env_ptr++;
			nptr++;
		}
		if ((*env_ptr == '=') && (*nptr == '\0'))
			return (env_ptr + 1);
		env_cur++;
	}
	return (NULL);
}





/**
 * stat_check_cat - stat check if file can be found.
 * @ptr: ptr vector:
 * Return: return 1 if found 0 if not found
 */

int stat_check_cat(char *ptr)
{
	if (access(ptr, F_OK) == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
