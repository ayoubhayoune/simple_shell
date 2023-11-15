#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * execute_cd - Execute the cd built-in command.
 *
 * @tokens: Array of strings containing the command and its arguments.
 */
void execute_cd(char **tokens)
{
	char *target_dir;

	if (tokens[1] == NULL || tokens[2] != NULL)
	{
		fprintf(stderr, "cd: usage: cd [DIRECTORY]\n");
		return;
	}

	target_dir = tokens[1];

	if (chdir(target_dir) != 0)
	{
		perror("cd");
	}
}
