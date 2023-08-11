#include "shell.h"

/**
 * main
 * return
 */

extern char **environ;

int main(void)
{
	char *argv[10];
	int argc = 0;
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
		if(!argc)
		{
			char *ptr1 ="/usr/bin/";
			strcat(ptr1, ptr);
			argv[argc++] = ptr1;
		}
		ptr = strtok(NULL, d);
		argv[argc] = ptr;
		argc++;
	}
	argv[argc++] = NULL;

	pid_t fid;

       if ((fid = fork()) == -1)
	       perror("SYSTEM CALL FAILS");

	if (fid == 0)
	{
		/*child process*/
		if ((execve(argv[0], argv, environ)) == -1)
		{
			perror("SYS FAILLED");
			exit;
		}
	}
	else
	{
		wait(NULL);
	}
}
	return (0);
}
