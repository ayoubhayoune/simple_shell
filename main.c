#include "shell.h"

/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: 0 on success, otherwise an error code.
 */

int main(int argc, char *argv[])
{
	char *input = NULL;

	/* Main shell loop */
	while (1)
	{
		/* Display shell prompt and read user input */
		display_prompt();
		input = read_input();

		/* Remove comments from the input */
		input = remove_comments(input);

		/* Handle file mode if a filename is provided as a command line argument */
		if (argc > 1)
		{
			execute_commands_from_file(argv[1]);
			exit(EXIT_SUCCESS);
		}

		/* Tokenize and execute the input command */
		char *processed_input = handle_variables(input);
		char **tokens = tokenize_input(processed_input);

		execute_command(tokens);

		/* Free allocated memory */
		free(input);
		free(processed_input);
		free_tokens(tokens);
	}

	return (0);
}
