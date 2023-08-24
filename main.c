#include "shell.h"
/**
* main - main program.
* Return: interger.
 */
int main(void)
{
	char *cmd = NULL, *cmd1 = NULL, *comand;
	int checks, argc = 0, checkp = 0, n = 1;
	char *argv[MAX];
	size_t b = 1;
	ssize_t bytes_read = 1;

while (1)
{
	if (isstatus())
		display_pmt();
	bytes_read = getline(&cmd, &b, stdin);
	if (bytes_read == -1)
		break;
	if (bytes_read > 1 && cmd[bytes_read - 1] == '\n')
		cmd[bytes_read - 1] = '\0';
	cmd1 = _strdup(cmd);
	cmd_check(cmd1, &argc, argv);
	argc++;
	argv[argc] = NULL;
	checks = stat_check(argv);
	checkp = get_path(argv[0], &comand);
	if (argc == 1 && ++n)
		continue;
	else if (checks == 1)
		execute_command(argv[0], argv, environ);
	else if (checkp)
		execute_command(comand, argv, environ);
	else
	{
		if ((_exitcmd(argv)) == 1)
			break;
		_perror("./hsh: %d : %s : not found\n", n, argv[0]);
	}
	free(comand);
	free(cmd1);
	n++;
}
	free(cmd);
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

	ptkn = _strtok(cmd, delime);
	argv[a] = ptkn;

	while (ptkn)
	{
		ptkn = _strtok(NULL, delime);
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
		int status;

		waitpid(pid, &status, 0);
	}
}
/**
 * isstatus - check stdin and stdout.
 *Return: 1|0
 */

int isstatus(void)
{
	return (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO));
}
