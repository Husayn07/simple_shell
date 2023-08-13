#include "shell.h" 
#include <sys/stat.h>
#include <sys/types.h>



/**
 * main - a fubction that locate the path to a dike in the environ.
 * @argc: vector count
 * @argv: vector array pointer to strings
 * @envp: environ variable
 * Return: pointer to part.
 */

char *get_path(char* argv)
{
	char *ptr = NULL;
	int i = 0;
	char *cmd = NULL;
	char *tok = NULL;
	int check = 2;

	ptr = _getenv("PATH");
	tok = strtok(ptr, ":");
	while(tok)
	{
		cmd = str_concat_(tok, "/", argv);
		
		check = stat_check_cat(cmd);
		if (check == 1)
			return (cmd);
		if (check == 0)
		{
			tok = strtok(NULL, ":");
			continue;
		}

	}
	return(argv);
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
	struct stat st;

	if (stat(ptr, &st) == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
