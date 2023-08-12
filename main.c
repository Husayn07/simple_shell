#include "shell.h"




int main(int argc, char *argv[], char **envp)
{
	char *cmd = NULL;
	size_t n = 0;
	int i;

while(1)
{
	/*Display prompt/cmd for exec.*/
	display_pmt();

	/*get cmd from user*/
	if((getline(&cmd, &n, stdin)) == -1)
		perror("input failled");

	/*need to formant user input*/
	cmd_check(cmd, &i, argv);
	argc = i;

	/*status check*/
	stat_check(argv, argc);

	/*call execution command*/
	execute_command(argv, envp);


	/*exit program*/
	if((_strcmp(argv[0], "exit")) == 0)
		exit(EXIT_SUCCESS);
	return (0);
}
}


/**
 * display_pmt - write $ on the console
 *
 * Return: 1 | 0 if sucessfull or failed
 */
int display_pmt()
{
	char c = '$';
	if (c)
	{
		write(1, &c, sizeof(char));
		return (1);
	}
	else
		return(0);
}

/**
 * cmd_check - check and format cmd input
 *@cmd: cmd input from user
 * 
 * Return: return int number of argumment and cmd input by the user
 */

int cmd_check(char *cmd, int *i, char *argv[])
{
	char *delime = (" \n");
	int a = 0;
	char *ptkn;

	ptkn = strtok(cmd, delime);
	argv[a] = ptkn;

	while(ptkn)
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
 */
void execute_command(char *argv[], char *envp[])
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
		if (execve(argv[0], argv, envp) == -1)
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
