#include "shell.h"

/**
* _strncmp - compare two strings until reaching n
* @str1: parameter 1
* @str2: parameter 2
* @n: the function compares the strings until it reaches n
*
* Return: 1 on success, 0 on failure
*/

int _strncmp(const char *str1, const char *str2, int n)
{
	int c;

	for (c = 0; c < n; c++)
	{
		if (str1[c] != str2[c])
			return (0);
	}
	return (1);
}

/**
* _strlen - length string count
* @str: input string to count
* Return: number of char's
*/

size_t _strlen(const char *str)
{
	int var = 0;

	if (!str)
		return (0);

	while (*str++)
		var++;
	return (var);
}

/**
**_strcpy - copy two strings
*@src: string 1
*@dest: string 2
*Return: final result string
*/

char *_strcpy(char *dest, const char *src)
{
	char *my_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (my_dest);
}

/**
**_strcat - concatenates two strings
*@src: string 1
*@dest: string 2
*Return: a string with the two strings appended
*/

char *_strcat(char *dest, char *src)
{
	int p = 0;
	int j = 0;

	while (dest[p] != '\0')
	{
		p++;
	}
	while (src[j] != '\0')
	{
		dest[p] = src[j];
		j++;
		p++;
	}
	dest[p] = '\0';
	return (dest);
}
