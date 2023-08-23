#include "shell.h"

/**
 * _perror - a function that print formatted test to stderr
 * @str: a string const
 * Return: 1 if succesfull 0 if failled.
 */


int _perror(const char *str, ...)
{
	va_list arg;

	int i;
	char a;

	va_start(arg, str);


	i = 0;
	while (str[i])
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
		else if ((str[i] == '%') && (str[++i] == 'd'))
		{
		}

		a = str[i];
		put_e(a);
		i++;
	}
	va_end(arg);

	return (0);
}

/**
 * put_e - write a charater into stderr
 * @c: char argument
 * Return: 1 if successful | 0 failled
 */

int put_e(char c)
{
	if ((write(STDERR_FILENO, &c, sizeof(char))) == 0)
		return (1);
	else
		return (0);
}

/**
 * putnum - write out formatted integer to strderr
 * @x: parameter
 * Return: 1
 */

int putnum(int x)
{
	int y = x, i = 0, t = 1, p = 0;

	while (x)
	{
		i++;
		x = x / 10;
		t = t * 10;
	}
	t = t / 10;
	while (i)
	{
		p = y / t;
		p = p % 10;
		put_e(p + 48);
		t = t / 10;
		i--;
	}
	return (0);
}

