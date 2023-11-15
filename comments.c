#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * remove_comments - Remove comments from a command line.
 * @input: User input string.
 * Return: Command string without comments.
 */
char *remove_comments(char *input)
{
	char *result = strdup(input);
	char *comment_pos;

	/* Find the position of the first '#' character */
	comment_pos = strchr(result, '#');

	if (comment_pos != NULL)
	{
		/* Remove the comment by truncating the string at the '#' character */
		*comment_pos = '\0';
	}

	return (result);
}
