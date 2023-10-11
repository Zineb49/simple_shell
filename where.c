#include "shell.h"

/**
 * where - search for a command in PATH directories
 * @cmd: cmd to append to path
 * Return: path string or NULL
 */

char *where(char *cmd)
{
	struct stat st;
	int i = 0;
	char *all_path = getenv("PATH");
	char **path = NULL;
	char *full_path = NULL;

	if (!all_path)
		return (NULL);

	path = string_split(all_path, ':');

	while (path[i])
	{
		full_path = malloc(strlen(path[i]) + strlen(cmd) + 2);
		if (!full_path)
			return (NULL);

		_strcpy(full_path, path[i]);
		strcat(full_path, "/");
		strcat(full_path, cmd);

		if (stat(full_path, &st) == 0)
		{
			split_free(path);
			return (full_path);
		}

		free(full_path);
		full_path = NULL;
		i++;
	}
	split_free(path);
	return (NULL);
}
