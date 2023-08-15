#include "shell.h"
#include <sys/types.h>
#include <sys/stat.h>

/**
 * stat_check - stat check if file can be found.
 * @argv: arg vector:
 * @argc: arg count:
 * Return: return 1 if found 0 if not found
 */

int stat_check(char *argv[], int argc)
{
	unsigned int i = 0;
	struct stat st;

	if (argc < 1)
	{
		printf("%d\n", argc);
		return (2);
	}
	else if (stat(argv[i], &st) == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
