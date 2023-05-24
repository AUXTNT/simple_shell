#include "shell.h"

/**
 * _eputs -  the input string printed
 * @str: print the string
 *
 * Return: NULL
 */
void _eputs(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		j++;
		_eputchar(str[j]);
	}
}

/**
 * _eputchar - the character c written to stderr
 * @c: print the character
 *
 * Return: 1 On success.
 * On error, return -1, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - the character c written to given fd
 * @c: Print the character
 * @fd: to write the filedescriptor to
 *
 * Return: 1 On success.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(fd, buf, j);
		j = 0;
	}
	if (c != BUF_FLUSH)
		buf[j++] = c;
	return (1);
}

/**
 * _putsfd - input string to be printed
 * @str: print an input string
 * @fd: to write the fileescriptor to
 *
 * Return: num of chars put
 */
int _putsfd(char *str, int fd)
{
	int j = 0;

	if (!str)
		return (0);
	while (*str)
	{
		j += _putfd(*str++, fd);
	}
	return (j);
}
