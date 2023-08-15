#include "shell.h"


int print_f(char *arr[])
{
	int i = 0;
	while(arr[i])
	{
		printf("%s   ", arr[i]);
		i++;
	}
		putchar('\n');
}
