#include "shell.h"
/**
 *_getline - Read The Input By User From Stdin
 *@buff: pointer to a pointer
 *Return: 1 on success | 0 on faliure
 */
int _getline(char **buff)
{
	int i, buffsize = sizeof(char);
	char c = 0;

	*buff = (char *)malloc(buffsize);
	if (*buff == NULL)
	{
		return (0);
	}
	for (i = 0; c != '\n'; i++)
	{
		read(STDIN_FILENO, &c, sizeof(char));
		if (c == '\n')
		{
			(*buff)[i] = '\0';
			return (1);
		}
		else
		(*buff)[i] = c;
		if (i >= buffsize)
		{
			*buff = realloc(*buff, buffsize + 1);
		}
	}
	(*buff)[i] = '\0';
	return (1);
}
