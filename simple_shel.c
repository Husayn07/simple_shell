#include "shell.h"

/**
 * main
 * return
 */


int main(void)
{
	char *buff;
	size_t n = 0;
	int argc = 0;
	char *argv[100];

	getline(&buff, &n, stdin);


	char *d = " \n";
	char *ptr = strtok(buff, d);

	while (ptr)
	{
		argv[argc] = ptr;
		ptr = strtok(NULL, d);
		argc++;
	}
	argv[argc++] = NULL;
	return (0);
}
