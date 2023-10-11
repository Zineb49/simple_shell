#include "shell.h"

/**
 * dirr - This checks if the string is a dir.
 * @str: string
 * Return: 1 if dir is found in the string or 0 if not found
 */

int dirr(char *str)
{
	int p = 0;

	if (str[0] == '/' || (str[0] == '.' && str[1] == '/'))
		p += 1;
	if (p > 0)
		return (1);
	return (0);
}
