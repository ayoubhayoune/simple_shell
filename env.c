#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * execute_env - Execute the env built-in command.
 *
 * @tokens: Array of strings containing the command and its arguments.
 */
void execute_env(char **tokens)
{
	char **env = environ;

	if (tokens[1] != NULL)
	{
		fprintf(stderr, "env: too many arguments\n");
		return;
	}

	/* Display the environment variables */
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
