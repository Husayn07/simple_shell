#include "shell.h"
/**
 * main - main program.
 * @argc
 * @argv
 * @envp
 * Return: interger.
 */
int main(void)
{
	char *cmd = NULL, *cmd1 = NULL;
	int check, argc = 0, i = 0, status = 1, count = 1;
	char *argv[MAX];

while (1 && status)
{
	display_pmt();

	fflush(stdin);
	_getline(&cmd);
	status = isatty(STDIN_FILENO);
	cmd1 = _strdup(cmd);

	cmd_check(cmd1, &argc, argv);
	argc++;
	argv[argc] = NULL;

	check = stat_check(argv, argc);
	if (check == 2)
		continue;
	else if (check == 1)
		execute_command(argv[0], argv, environ);
	i = get_path(argv[0]);
	if (i)
	{
		execute_command(comand, argv, environ);
	}
	else
	{
		if ((strcmp(argv[0], "exit")) == 0)
			break;
		if ((strcmp(argv[0], "EXIT")) == 0)
			break;
		_perror("./hsh: %d: %s: not found\n",count, argv[0]);
	}
	free(comand);
	count++;
}
	return (0);
}


/**
 * display_pmt - write $ on the console
 *
 * Return: 1 | 0 if sucessfull or failed
 */
int display_pmt(void)
{
	char c = '$';
	char d = '/';

	if (c)
	{
		write(1, &d, 1);
		write(1, &c, 1);
		return (1);
	}
	else
		return (0);
}

/**
 * cmd_check - check and format cmd input
 *@cmd: cmd input from user
 *@i: address of parameter i
 *@argv: array of fuction.
 *Return: return int number of argumment and cmd input by the user
 */

int cmd_check(char *cmd, int *i, char *argv[])
{
	char *delime = (" \n");
	int a = 0;
	char *ptkn;

	ptkn = strtok(cmd, delime);
	argv[a] = ptkn;

	while (ptkn)
	{
		ptkn = strtok(NULL, delime);
		a++;
		argv[a] = ptkn;
	/*printf("%s\n", ptr[a]);*/
	}
	*i = a;
	return (0);
}



/**
 * execute_command - Execute a command.
 * @argv: arg vector
 * @envp: environ variable
 * @cmd: take the argv[0]
 * Return: Void.
 */
void execute_command(char *cmd, char *argv[], char *envp[])
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/*child process*/
		if (execve(cmd, argv, envp) == -1)
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
