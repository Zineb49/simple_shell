#include "shell.h"

/**
 * split_free - frees split_string
 * @str: pointer to char * to free
 *
 * Return: void
 */

void split_free(char **str)
{
	int a = 0;

	if (str)
	{
		while (str[a])
		{
			free(str[a]);
			str[a] = NULL;
			a++;
		}
		free(str);
		str = NULL;
	}
}
