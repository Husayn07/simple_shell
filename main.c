#include "shell.h"
<<<<<<< HEAD
=======
/**
* main - main program.
* Return: interger.
 */
int main(void)
{
	char *cmd = NULL, *cmd1 = NULL, *comand;
	int checks, argc = 0, checkp = 0, status = 1;
	char *argv[MAX];
	size_t n = 1;

while (1 && status)
{
	display_pmt();

	getline(&cmd, &n, stdin);
	status = isatty(STDIN_FILENO);
	cmd1 = _strdup(cmd);

	cmd_check(cmd1, &argc, argv);
	argc++;
	argv[argc] = NULL;

	checks = stat_check(argv);
	checkp = get_path(argv[0], &comand);
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

>>>>>>> 08166b44cf598315666d741b71509f85df337302

/**
 * main - Entry point of the simple shell program
 *
 * Return: Always returns 0
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
