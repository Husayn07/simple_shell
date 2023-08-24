#include "shell.h"
<<<<<<< HEAD
=======
/**
* main - main program.
* Return: interger.
 */
int main(void)
{
	char *cmd = NULL, *cmd1 = NULL, *comand = NULL;
	int checks = 1, argc = 0, checkp = 0, n = 1;
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
	free(cmd1);
	n++;
}
	free(cmd);
	free(comand);
	return (0);
}

>>>>>>> 08166b44cf598315666d741b71509f85df337302

/**
 * main - Entry point of the simple shell program
 *
<<<<<<< HEAD
 * Return: Always returns 0
=======
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
>>>>>>> 3a27f151c97ffc997d4fb0e7cba70d06d02989ab
 */
<<<<<<< HEAD
int main(void)
=======

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
>>>>>>> 08166b44cf598315666d741b71509f85df337302
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *token;
    char *args[2];
    int i = 0;

<<<<<<< HEAD
    while (1)
    {
        printf("$ ");

        read = getline(&line, &len, stdin);
        if (read == -1)
        {
            if (errno == 0)
                break;
            perror("getline");
            exit(EXIT_FAILURE);
        }

        if (line[read - 1] == '\n')
            line[read - 1] = '\0';

        token = strtok(line, " ");
        while (token != NULL)
        {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (strcmp(args[0], "exit") == 0)
            break;

        if (strcmp(args[0], "cd") == 0)
            _cd(args);
        else
            printf("Command not found: %s\n", args[0]);
    }

    free(line);
    return (0);
=======
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
>>>>>>> 3a27f151c97ffc997d4fb0e7cba70d06d02989ab
}
/**
 * isstatus - check stdin and stdout.
 *Return: 1|0
 */

int isstatus(void)
{
	return (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO));
}
