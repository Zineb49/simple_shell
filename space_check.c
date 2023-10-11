#include "shell.h"

/**
*space_check - This counts the spaces in a given string
*@str: Pointer to the given string
*Return: 0 when there is no space, non-zero for space
*/

size_t space_check(char *str)
{
	int i = 0, sp = 0;

	while (str[i])
	{
		if (isspace(str[i]))
		{
			sp++;
		}
		i++;
	}
	return (sp);
}
