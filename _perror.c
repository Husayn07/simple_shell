#include "shell.h"
#include <stdarg.h>

/**
 * put_e - Writes a character into stderr
 * @c: Char argument
 * Return: 1 if successful, 0 if failed
 */
<<<<<<< HEAD
<<<<<<< HEAD
int put_e(char c)
{
    if (write(STDERR_FILENO, &c, sizeof(char)) == -1)
        return 0;
    return 1;
=======


=======
>>>>>>> 3a27f151c97ffc997d4fb0e7cba70d06d02989ab
int _perror(const char *str, ...)
{
	const char *ptr = str;
	int printed_chars = 0;
	va_list arg;

	va_start(arg, str);

	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == 's')
			{
				char *arr = va_arg(arg, char *);

				while (*arr != '\0')
				{
					put_e(*arr);
					arr++;
					printed_chars++;
				} ptr++;
			}
			else if (*ptr == 'd')
			{
				int num = va_arg(arg, int);

				printed_chars += putnum(num);
				ptr++;
			}
		}
		else
		{
			put_e(*ptr);
			printed_chars++;
		} ptr++;
	}
	va_end(arg);
<<<<<<< HEAD

	return (0);
>>>>>>> 08166b44cf598315666d741b71509f85df337302
=======
	return (printed_chars);
>>>>>>> 3a27f151c97ffc997d4fb0e7cba70d06d02989ab
}


/**
 * putnum - Writes out a formatted integer to stderr
 * @x: Parameter
 * Return: 1
 */
int putnum(int x)
{
<<<<<<< HEAD
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
=======
	if (write(STDERR_FILENO, &c, sizeof(char)) == -1)
	{
		perror("write");
		return (0);
	}
	return (1);
>>>>>>> 3a27f151c97ffc997d4fb0e7cba70d06d02989ab
}

/**
 * _perror - Prints formatted text to stderr
 * @str: A string const
 * Return: 1 if successful, 0 if failed.
 */
int _perror(const char *str, ...)
{
<<<<<<< HEAD
<<<<<<< HEAD
    va_list arg;
    int i = 0;
=======
	int y = x, i = 0, t = 1, p = 0;
=======
	int printed_chars = 0, num_digits, i, temp;
	char digits[10];
>>>>>>> 3a27f151c97ffc997d4fb0e7cba70d06d02989ab

	if (x == 0)
	{
		put_e('0');
		return (1);
	}
	else if (x < 0)
	{
		put_e('-');
		x = -x;
		printed_chars++;
	}
	num_digits = 0;
	temp = x;
	while (temp > 0)
	{
		temp /= 10;
		num_digits++;
	}
<<<<<<< HEAD
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
=======

	for (i = num_digits - 1; i >= 0; i--)
	{
		digits[i] = (x % 10) + '0';
		x /= 10;
	}
	for (i = 0; i < num_digits; i++)
	{
		printed_chars += put_e(digits[i]);
	}
	return (printed_chars);
>>>>>>> 3a27f151c97ffc997d4fb0e7cba70d06d02989ab
}
