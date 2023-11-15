#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * display_prompt - Display the shell prompt.
 */
void display_prompt(void)
{
	printf("$ ");
	fflush(stdout);
}

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
