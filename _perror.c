#include "shell.h"
#include <stdarg.h>

/**
 * put_e - Writes a character into stderr
 * @c: Char argument
 * Return: 1 if successful, 0 if failed
 */
<<<<<<< HEAD
int put_e(char c)
{
    if (write(STDERR_FILENO, &c, sizeof(char)) == -1)
        return 0;
    return 1;
=======


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
>>>>>>> 08166b44cf598315666d741b71509f85df337302
}

/**
 * putnum - Writes out a formatted integer to stderr
 * @x: Parameter
 * Return: 1
 */
int putnum(int x)
{
<<<<<<< HEAD
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
        put_e(p + '0');
        t = t / 10;
        i--;
    }
    return 1;
=======
	if ((write(STDERR_FILENO, &c, sizeof(char))) == 0)
		return (1);
	else
		return (0);
>>>>>>> 08166b44cf598315666d741b71509f85df337302
}

/**
 * _perror - Prints formatted text to stderr
 * @str: A string const
 * Return: 1 if successful, 0 if failed.
 */
int _perror(const char *str, ...)
{
<<<<<<< HEAD
    va_list arg;
    int i = 0;
=======
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
>>>>>>> 08166b44cf598315666d741b71509f85df337302

    va_start(arg, str);
    while (str[i])
    {
        if ((str[i] == '%') && (str[++i] == 's'))
        {
            char *arr = va_arg(arg, char *);
            int b = 0;
            while (arr[b])
            {
                put_e(arr[b]);
                b++;
            }
            i++;
        }
        else if ((str[i] == '%') && (str[++i] == 'd'))
        {
            int num = va_arg(arg, int);
            putnum(num);
            i++;
        }
        else
        {
            put_e(str[i]);
            i++;
        }
    }
    va_end(arg);
    return 1;
}
