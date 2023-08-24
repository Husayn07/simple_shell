#include "shell.h"

/**
 * _getline - Read input from stdin
 * @info: Parameter struct
 * @buff: Pointer to a pointer for storing the input
 * @buffsize: Pointer to a variable storing the buffer size
 *
 * Return: 1 on success, 0 on failure
 */
int _getline(info_t *info, char **buff, size_t *buffsize)
{
	int i;
	char c = 0;

	(void)info;

        *buff = (char *)malloc(*buffsize);
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
		if ((size_t)i >= *buffsize)
                {
                        *buffsize += sizeof(char);
                        *buff = realloc(*buff, *buffsize);
                        if (*buff == NULL)
                                return (0);
                }
        }
        (*buff)[i] = '\0';
        return (1);
}
