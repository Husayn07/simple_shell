#include "shell.h"

/**
 * _perror - a function that print formatted test to stderr
 * @str: a string const
 * Return: 1 if succesfull 0 if failled.
 */
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
 * put_e - write a charater into stderr
 * @c: char argument
 * Return: 1 if successful | 0 failled
 */

int put_e(char c)
{
	if (write(STDERR_FILENO, &c, sizeof(char)) == -1)
	{
		perror("write");
		return (0);
	}
	return (1);
}

/**
 * putnum - write out formatted integer to strderr
 * @x: parameter
 * Return: 1
 */

int putnum(int x)
{
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
