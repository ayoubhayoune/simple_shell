#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * read_input - Read user input from the command line.
 *
 * Return: A pointer to the input string.
 */
char *read_input(void)
{
	char *input = NULL;
	size_t bufsize = 0;
	ssize_t characters_read;

	/* Read a line of input from the user */
	characters_read = getline(&input, &bufsize, stdin);

	if (characters_read == -1)
	{
		free(input);  /* Free memory in case of an error or end of file condition */
		return (NULL);
	}

	/* Remove the newline character at the end of the input */
	if (characters_read > 0 && input[characters_read - 1] == '\n')
		input[characters_read - 1] = '\0';

	return (input);
}

/**
 * handle_eof - Handles the "end of file" condition.
 *
 * @input: Input string to check.
 *
 * Return:
 * 1 if it is the end of file, 0 otherwise.
 */

int handle_eof(char *input)
{
	if (input == NULL)
	{
		printf("\n");
		return (1);
	}

	return (0);
}
