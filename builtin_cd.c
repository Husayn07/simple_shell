#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "shell.h"

int _cd(char **args)
{
	char *new_dir;
       char *old_dir = getcwd(NULL, 0);

	if (args[1] == NULL)
	{
		new_dir = getenv("HOME");
		if (new_dir == NULL)
		{
		       	fprintf(stderr, "cd: HOME not set\n");
			return (0);
		}
	}
	else if (strcmp(args[1], "-") == 0)
	{
		new_dir = getenv("OLDPWD");
	       	if (new_dir == NULL)
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
			return (0);
		}
		printf("%s\n", new_dir);
	}
	else
	{
		new_dir = args[1];
	}

	if (chdir(new_dir) != 0)
	{
		perror("cd");
		return (0);
	}
	setenv("OLDPWD", old_dir, 1);
	setenv("PWD", getcwd(NULL, 0), 1);
	free(old_dir);
	return (1);
}
