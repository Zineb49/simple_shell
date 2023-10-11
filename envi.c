#include "shell.h"

/**
 * _envi_vari - environmental variable
 *@envp: Pointer from main function
 */

void _envi_vari(char **envp)
{
	int p = 0;

	while (envp[p] != NULL)
	{
		write(STDOUT_FILENO, envp[p], strlen(envp[p]));
		write(STDOUT_FILENO, "\n", 1);
		p++;
	}
}
