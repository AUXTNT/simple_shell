#include "shell.h"

/**
 * _erratoi - an integer string to be converted
 * @s: convert the string
 * Return: 0 Always if no nums in string, otherwise convert num
 *       -1 on error
 */
int _erratoi(char *s)
{
	int j = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++; /* TODO: why does 255 make main return? */
	for (j = 0;  s[j] != '\0'; j++)
	{
		if (s[j] >= '0' && s[j] <= '9')
		{
			result += (s[j] - '0');
			result *= 10;
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - an error message printed
 * @info: return info struct & the parameter
 * @estr: write string containing specified error type
 * Return: if no numbers in string 0, otherwise convert num
 *        on error -1
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function prints a decimal function (integer) num (base 10)
 * @input: the input
 * @fd: write to the filedescriptor
 *
 * Return: num of printed characters
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int j, count = 0;
	unsigned int _abs_, cursor;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	cursor = _abs_;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (_abs_ / j)
		{
			__putchar('0' + cursor / j);
			count++;
		}
		cursor %= j;
	}
	__putchar('0' + cursor);
	count++;

	return (count);
}

/**
 * convert_num - a clone of itoa, function converter
 * @num: num
 * @base: base
 * @flags: flag argument
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: modify the address of the string
 *
 * Return:0 Always;
 */
void remove_comments(char *buf)
{
	int j;

	for (j = 0; buf[j] != '\0'; j++)
		if (buf[j] == '#' && (!j || buf[j - 1] == ' '))
		{
			buf[j] = '\0';
			break;
		}
}
