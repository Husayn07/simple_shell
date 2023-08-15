#include "shell.h"

/**
 * main - main program.
 * @argc
 * @argv
 * @envp
 * Return: interger.
 */

int main(int argc, char *argv[], char **envp)
{
	char *cmd = NULL;
	char *cmd1 = NULL;
	size_t n = 0;
	int i;
	int check;

while(1)
{
	/*Display prompt/cmd for exec.*/
	display_pmt();

	/*get cmd from user*/
	if((getline(&cmd, &n, stdin)) == -1)
		perror("input failled");
	/*create copy fomr cmd to avoid */
	cmd1 = _strdup(cmd);

	/*need to formant user input*/
	cmd_check(cmd1, &i, argv);
	argc = i;

	/*status check*/
	/* start execution comannd*/
	check = stat_check(argv, argc);
	if(check == 2)
		continue;
	if(check == 1)
		execute_command(argv[0], argv, envp);
	if(check == 0)
	{
		i = get_path(argv[0]);
		argv[0] = comand;
		if(comand)
		{
		execute_command(argv[0], argv,  envp);
		}
		else
		perror("comand not found");
	}
	/*call execution command done*/


	/*exit program*/
	/* need to fix strcmp*/
	if((strcmp(argv[0], "exit")) == 0)
		break;
	if((strcmp(argv[0], "EXIT")) == 0)
		break;

	free(comand);
}
	return (0);
}


/**
 * display_pmt - write $ on the console
 *
 * Return: 1 | 0 if sucessfull or failed
 */
int display_pmt()
{
	char c = '$';
	char d = '/';
	if (c)
	{
		write(1, &d,1);
		write(1, &c,1);
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
