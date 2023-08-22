#include "shell.h"
/**
 * main - main program.
 * Return: interger.
 */
int main(void)
{
	char *cmd = NULL, *cmd1 = NULL;
	int checks, argc = 0, checkp = 0, status = 1;
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

	checks = stat_check(argv, argc);
	checkp = get_path(argv[0]);
	if (argc == 1)
		continue;
	else if (checks == 1)
		execute_command(argv[0], argv, environ);
	else if (checkp)
		execute_command(comand, argv, environ);
	else
	{
		if ((_exitcmd(argv)) == 1)
			break;
		_perror("./hsh: %s: not found\n", argv[0]);
	}
	free(comand);
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
	char *delime = (" ");
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
		wait(NULL);
	}
}

/**
 * main - Entry point of the simple shell program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * @env: The array of environment variables
 * Return: Always returns 0
 */
int main(int argc, char **argv, char **env)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *token;
    char *args[2];
    int i = 0;

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
}
