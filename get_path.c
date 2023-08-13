#include "shell.h" 
#include <sys/stat.h>



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
	char *ptr1[MAX] = {NULL,NULL, NULL, NULL, NULL};
	int i = 0;
	char *cmd = NULL;

	ptr = _getenv("PATH");
	ptr1[i] = strtok(ptr, ":");
	while(ptr[i])
	{
		i++;
		ptr1[i] = strtok(NULL, ":");
	}

	for(;i >= 0; i--)
	{
		cmd = str_concat_(ptr1[i], "/", argv);
		struct stat st;

		if ((stat(cmd, &st)) == 0)
			return (cmd);
	}
  return (NULL);
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
