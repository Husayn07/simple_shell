#include "shell.h"

/**
 * main
 * return
 */


int main(int argc, char *argv[])
{
	char *buff;
	size_t n = 0;
	char c = '$';

	write(1, &c, sizeof(char));

	if ((getline(&buff, &n, stdin)) == -1)
		perror("INPUT FAILLED");

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
