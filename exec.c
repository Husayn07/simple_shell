#include "shell.h"

int main()
{
	char *buff = "/bin/ls";
	char *argv[] = {"ls","-l", NULL};

	execve(buff, argv, NULL);
}
