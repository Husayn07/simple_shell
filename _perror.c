#include "shell.h"
#include <stdarg.h>

/**
 * put_e - Writes a character into stderr
 * @c: Char argument
 * Return: 1 if successful, 0 if failed
 */
int put_e(char c)
{
    if (write(STDERR_FILENO, &c, sizeof(char)) == -1)
    return (1);

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
	return (printed_chars);
}


/**
 * putnum - Writes out a formatted integer to stderr
 * @x: Parameter
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
        put_e(p + '0');
        t = t / 10;
        i--;
    }
    return 1;
	if ((write(STDERR_FILENO, &c, sizeof(char))) == 0)
		return (1);
	else
		return (0);

	if (write(STDERR_FILENO, &c, sizeof(char)) == -1)
	{
		perror("write");
		return (0);
	}
	return (1);
}

/**
 * _perror - Prints formatted text to stderr
 * @str: A string const
 * Return: 1 if successful, 0 if failed.
 */
int _perror(const char *str, ...)
{
    va_list arg;
    int i = 0;

	int y = x, i = 0, t = 1, p = 0;

	int printed_chars = 0, num_digits, i, temp;
	char digits[10];

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

	return (0);
}

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
}
