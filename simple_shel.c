#include "shell.h"

/**
 * main
 * return
 */


int main(void)
{
	char *argv[10];
	int argc;
	char *buff;
	size_t n = 0;
	char c = '$';
	char *d = " \n";
	char *ptr;

while(1)
{
	write(1, &c, sizeof(char));

	fflush(stdin);
	if ((getline(&buff, &n, stdin)) == -1)
		perror("INPUT FAILLED");

	ptr = strtok(buff, d);
	while (ptr)
	{
		argv[argc] = ptr;
		ptr = strtok(NULL, d);
		argc++;
	}
	argv[argc++] = NULL;

	pid_t fid;

       if ((fid = fork()) == -1)
	       perror("SYSTEM CALL FAILS");

	if (fid == 0)
	{
		/*child process*/
		if ((execve(argv[0], argv, NULL)) == -1)
		{
			perror("SYS FAILLED");
			exit;
		}
	}
	else
	{
		wait(NULL);
		int i = 0;
		while(argv[i])
		{
			printf("%s ", argv[i]);
			i++;
		}
		putchar('\n');
	}
}
	return (0);
}
