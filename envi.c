#include "shell.h"

/**
 * _envi_vari - environmental variable
 *@envp: Pointer from main function
 */

void _envi_vari(char **envp)
{
	int i = 0;

	while (envp[i] != NULL)
	{
		write(STDOUT_FILENO, envp[i], strlen(envp[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
