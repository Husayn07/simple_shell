#include "shell.h"
/**
 *_getline - Read The Input By User From Stdin
 *@buff: pointer to an adresss
 *Return: Input
 */
char _getline(char **buff)
{
	int i, buffsize = sizeof(char);
	char c = 0;

	*buff = (char *)malloc(buffsize);
	if (*buff == NULL)
	{
		return ('\n');
	}
	for (i = 0; c != '\n'; i++)
	{
		fflush(stdin);
		read(STDIN_FILENO, &c, sizeof(char));
		if (c == '\n')
		{
			(*buff)[i] = '\0';
			return (EOF);
		}
		else
		(*buff)[i] = c;
		if (i >= buffsize)
		{
			*buff = realloc(*buff, buffsize + 1);
		}
	}
	(*buff)[i] = '\0';
	return (EOF);
}
