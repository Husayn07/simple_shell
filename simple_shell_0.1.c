#include "shell.h"

/**
 * execute_command - Execute a command.
 * @cmd: The command to execute.
 * @argv: The argument vector containing the command and its arguments.
 */
void execute_command(char *cmd, char *argv[])
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(cmd, argv) == -1)
		{
			perror("Command execution failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
