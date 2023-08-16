#include "shell.h"

/**
 * _perror - a function that print formatted test to stderr
 * @str: a string const
 * Return: 1 if succesfull 0 if failled.
 */

int put_e(char c);
int _perror(const char *str, ...)
{
	va_list arg;
	va_start(arg, str);

	int i = 0;
	while(str[i])
	{
		if ((str[i] == '%') && (str[++i] == 's'))
		{
			char *arr = va_arg(arg, char *);
			int b = 0;
			while (arr[b])
			{
				char s = arr[b];
				put_e(s);
				b++;
			}
			i++;
		}
		char a = str[i];
		put_e(a);
		i++;
	}
	va_end(arg);
}

/**
 * put_e - write a charater into stderr
 * @c: char argument
 * Return: 1 if successful | 0 failled
 */

int put_e(char c)
{
	if ((write(2, &c, sizeof(char)))== 0)
		return (1);
	else
		return (0);
}

