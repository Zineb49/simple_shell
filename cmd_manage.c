#include "shell.h"

/**
 *print_error - print the error and exit the program
 *@exit_code: the exit code
 *@argument: arg
 */

void print_error(int exit_code, char *argument)
{
	perror(argument);
	exit(exit_code);
}

/**
 * **func_helper - func to make sure we have the right argv
 * @argv: argument vector coming from main function
 * Return: to return the argv we have checked
 */

char **func_helper(char **argv)
{
	char *temp;

	if (!argv)
		print_error(1, "hsh");

	if (!dirr(argv[0]))
	{
		temp = malloc(strlen(argv[0]) + 1);
		strcpy(temp, argv[0]);
		free(argv[0]);
		argv[0] = NULL;
		argv[0] = where(temp);
		free(temp);
	}

	return (argv);
}

/**
 * manage_cmd - handle user input and execute commands
 * @buffer: user input
 * @envp: environement pointer
 * Return: 0 on sucess, 1 on failure, -1 to terminate terminal
 */

int manage_cmd(char *buffer, char **envp)
{
	pid_t pid;
	int status;
	char **argv;
	char *cmd;

	argv = string_split(buffer, ' ');
	cmd = argv[0];
	argv = func_helper(argv);

	if (!argv[0])
	{
		fprintf(stderr, "hsh: 1: %s: not found\n", cmd);
		return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
			print_error(126, argv[0]);
	}
	else if (pid > 0)
	{
		wait(&status);
		if (WIFEXITED(status) != 0 && WEXITSTATUS(status) != 0)
			fprintf(stderr, "hsh: 1: %s: not found\n", cmd);
		else if (WIFSIGNALED(status) != 0)
			print_error(WTERMSIG(status), cmd);
	}

	else
		print_error(-1, argv[0]);

	split_free(argv);

	return (0);
}
