#include "shell.h"

#define MAX_ARGS 10

void execute_command(char *argv[]);

/**
 * main - Entry point of the shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *buff = NULL;
	size_t n = 0;
	char prompt = '$';
	char *argv[MAX_ARGS + 1];
	int argc;
	char *token;

	while (1)
	{
		write(STDERR_FILENO, &prompt, sizeof(char));

		if (getline(&buff, &n, stdin) == -1)
		{
			perror("Input failed");
			continue;
		}

		buff[strcspn(buff, "\n")] = '\0';

		argc = 0;
		token = strtok(buff, " ");
		while (token && argc < MAX_ARGS)
		{
			argv[argc++] = token;
			token = strtok(NULL, " ");
		}
		argv[argc] = NULL;

		if (argc == 0)
		{
			continue;
		}

		if (strcmp(argv[0], "exit") == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}

		execute_command(argv);
	}

	free(buff);
	return (EXIT_SUCCESS);
}

/**
 * execute_command - Execute a command.
 * @argv: The argument vector containing the command and its arguments.
 */
void execute_command(char *argv[])
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(argv[0], argv) == -1)
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
