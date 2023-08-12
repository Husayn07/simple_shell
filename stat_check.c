#include "shell.h"
#include <sys/types.h>
#include <sys/stat.h>

/**
 * stat_check - stat evaluatio
 * @argv: arg vector:
 * @argc: arg count:
 * Return: Always 0.
 */

int stat_check(char *argv[], int argc)
{
	unsigned int i = 0;
	struct stat st;

	if (argc < 1)
	{
		;
	}
	if (stat(argv[i], &st) == 0)
	{
		printf(" FOUND\n");
	}
	else
	{
		printf(" NOT FOUND\n");
	}
  return (0);
}
