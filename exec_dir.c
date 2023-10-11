#include "shell.h"

/**
*isdir - This checks existence of dir in the string and gets it extracted.
*@str: Pointer to the string
*Return: extracted dir from the string.
*/

char *isdir(char *str)
{
	int i = 0, y = 0;
	char *str2 = "/";

	while (str[i])
	{
		if (str[i] == str2[y])
		{
			while (str[y])
			{
				str[y] = str[i];
				y++;
				i++;
			}
		}
		i++;
	}
	return (str);
}
