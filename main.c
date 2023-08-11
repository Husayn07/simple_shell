#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;
#define MAX 20

char *cmd_check(char *cmd, int *i);
int display_pmt();

int main(int argc, char *argv[], char **envp)
{
	char *cmd = NULL;
	size_t n = 0;
	int i;
	char *ptmd[MAX];

while(1)
{
	/*Display prompt/cmd for exec.*/
	display_pmt();

	/*get cmd from user*/
	if((getline(&cmd, &n, stdin)) == -1)
		perror("input failled");

	/*need to formant user input*/
	argv[0] = cmd_check(cmd, &i);

	argc = i;

	printf("%d, %s", argc, argv[0]);

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

char *cmd_check(char *cmd, int *i)
{
	char *ptcmd;
	char *delime = (" \n");
	int a = 0;
	char *ptr;

	ptr = strtok(cmd, delime);
	ptcmd = ptr;

	while(ptr)
	{
		ptr = strtok(NULL, delime);
		a++;
	}
	*i = a;
	return (ptcmd);
}
