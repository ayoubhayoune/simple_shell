#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * handle_separator - Handle commands separated by ;, &&, or ||.
 *
 * @input: User input string.
 */
void handle_separator(char *input)
{
	char *separator = ";";
	char *token;
	char *saveptr;

	token = strtok_r(input, separator, &saveptr);
	while (token != NULL)
	{
		/* Process each command token */
		process_command(token);

		/* Get the next command token */
		token = strtok_r(NULL, separator, &saveptr);
	}
}

/**
 * process_command - Process an individual command.
 *
 * @command: Command string.
 */
void process_command(char *command)
{
	/* Tokenize the command */
	char **tokens = tokenize_input(command);

	if (tokens != NULL)
	{
		/* Execute the command */
		execute_command(tokens);

		/* Free memory allocated for tokens */
		free_tokens(tokens);
	}
}

/**
 * free_tokens - Free memory allocated for command tokens.
 *
 * @tokens: Array of strings containing command tokens.
 */
void free_tokens(char **tokens)
{
	char **ptr = tokens;

	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(tokens);
}
