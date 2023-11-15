#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * is_builtin - Check if a command is a built-in.
 *
 * @command: Command to check.
 * Return: 1 if the command is a built-in, 0 otherwise.
 */
int is_builtin(char *command)
{
	if (command == NULL)
		return (0);

	if (strcmp(command, "exit") == 0 || strcmp(command, "env") == 0 ||
	    strcmp(command, "setenv") == 0 || strcmp(command, "unsetenv") == 0 ||
	    strcmp(command, "cd") == 0 || strcmp(command, "alias") == 0)
	{
		return (1); /* Command is a built-in */
	}

	return (0); /* Command is not a built-in */
}

/**
 * execute_builtin - Execute a built-in command.
 *
 * @tokens: Array of strings containing the command and its arguments.
 * Return: 1 if the command is a built-in, 0 otherwise.
 */
int execute_builtin(char **tokens)
{
	if (tokens == NULL || tokens[0] == NULL)
		return (0); /* Empty command, not a built-in */

	if (strcmp(tokens[0], "exit") == 0)
	{
		/* Add any cleanup or exit procedures here if needed */
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(tokens[0], "env") == 0)
	{
		execute_env();
		return (1); /* Command is a built-in */
	}
	else if (strcmp(tokens[0], "setenv") == 0)
	{
		execute_setenv(tokens);
		return (1); /* Command is a built-in */
	}
	else if (strcmp(tokens[0], "unsetenv") == 0)
	{
		execute_unsetenv(tokens);
		return (1); /* Command is a built-in */
	}
	else if (strcmp(tokens[0], "cd") == 0)
	{
		execute_cd(tokens);
		return (1); /* Command is a built-in */
	}
	else if (strcmp(tokens[0], "alias") == 0)
	{
		execute_alias(tokens);
		return (1); /* Command is a built-in */
	}

	return (0); /* Command is not a built-in */
}
