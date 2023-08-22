#include "shell.h"

/**
 * _exitcmd - exit command line interface
 * @agrv: vector parameter
 * Return 1 on sucesss | 0 on faliure
 */

int _exitcmd(char *argv[])
{
		if ((strcmp(argv[0], "exit")) == 0)
			return (1);
		if ((strcmp(argv[0], "EXIT")) == 0)
			return (1);
		return(0);
}
