#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * execute_commands_from_file - Execute commands from a file.
 * @filename: Name of the file containing commands.
 */
void execute_commands_from_file(const char *filename)
{
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = getline(&line, &len, file)) != -1)
	{
		/* Remove newline character from the end of the line */
		if (read > 0 && line[read - 1] == '\n')
		{
			line[read - 1] = '\0';
		}

		/* Process and execute the command from the file */
		process_and_execute_command(line);
	}

	free(line);
	fclose(file);
}

/**
 * process_and_execute_command - Process and execute a command from a file.
 * @command: Command string.
 */
void process_and_execute_command(char *command)
{
	/* Handle any preprocessing steps if needed */

	/* Tokenize, handle variables, and execute the command */
	char *processed_command = handle_variables(command);

	execute_command(tokenize_input(processed_command));

	/* Free memory if needed */
	free(processed_command);
}
