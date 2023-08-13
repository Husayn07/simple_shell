#include "shell.h" 
#include <sys/stat.h>
#include <sys/types.h>



/**
 * main - a function that locate the path to a file in the environ.
 * @argv: vector array pointer to strings
 * Return: pointer to part.
 */

int get_path(char* argv, char *ptrx)
{
	char *ptr = NULL;
	char *cmd = NULL;
	char *tok = NULL;
	int check = 0;

	ptr = _getenv("PATH");
	char *ptr1 = _strdup(ptr);
	tok = strtok(ptr1, ":");
	while(tok)
	{
		cmd = str_concat_(tok, "/", argv);
		printf("%s,  cmd\n", cmd);	
		check = stat_check_cat(cmd);
		if (check == 1)
		{
			ptrx = _strdup(cmd);
			return (1);
		}
		free(cmd);
		tok = strtok(NULL, ":");
	}
	free(ptr1);
	return (0);
}



char *_getenv(char *path_name)
{
	char **environ_cursor, *env_ptr, *name_ptr;

	environ_cursor = environ;
	while (*environ_cursor)
	{
		env_ptr = *environ_cursor;
		name_ptr = path_name;
		while (*env_ptr == *name_ptr)
		{
			if (*env_ptr == '=')
				break;
			env_ptr++;
			name_ptr++;
		}
		if ((*env_ptr == '=') && (*name_ptr == '\0'))
			return (env_ptr + 1);
		environ_cursor++;
	}
	return (NULL);
}





/**
 * stat_check - stat check if file can be found.
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
