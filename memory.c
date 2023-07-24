
#include "shell.h"

/**
 * bfree - frees a pointer and address of NULLs
 * @ptr: free the pointers address
 *
 * Return: 1 if freed, 0 otherwise.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

