#include "shell.h"
#include <sys/types.h>
#include <sys/stat.h>

/**
 * stat_check - stat check if file can be found.
 * @argv: arg vector:
 * Return: return 1 if found 0 if not found
 */

int stat_check(char *argv[])
{
	unsigned int i = 0;
	struct stat st;

	if (stat(argv[i], &st) == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
