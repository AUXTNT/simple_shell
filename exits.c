#include "shell.h"

/**
 **_strncpy - string copied
 *@dest: destination string to be copied to
 *@src: the source string
 *@n: the characters amount to be copied
 *Return: concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		i++;
		dest[i] = src[i];
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			j++;
			dest[j] = '\0';
		}
	}
	return (s);
}

/**
 **_strncat - two strings concatenated
 *@dest: string one
 *@src: string two
 *@n: bytes to be maximally used
 *Return: concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		i++;
		j++;
		dest[i] = src[j];
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr -  string character located
 *@s: parsed the string
 *@c: look for the character
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
