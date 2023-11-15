#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * expand_tokens - Resize the tokens array if necessary.
 *
 * @tokens: Array of strings containing the tokens.
 * @token_count: Current count of tokens.
 * @bufsize: Current buffer size.
 * Return: Resized tokens array.
 */
char **expand_tokens(char **tokens, size_t token_count, size_t *bufsize)
{
	/* Resize the tokens array if necessary */
	if (token_count >= *bufsize)
	{
		*bufsize += 64; /* Increase the buffer size */
		tokens = realloc(tokens, sizeof(char *) * (*bufsize));
		if (tokens == NULL)
		{
			perror("Reallocation error");
			exit(EXIT_FAILURE);
		}
	}
	return (tokens);
}

/**
 * tokenize_input - Tokenize user input into individual commands and arguments.
 *
 * @input: User input string.
 * Return: An array of strings containing the tokens.
 */
char **tokenize_input(char *input)
{
	const char *delimiter = " "; /* Token delimiter (space) */
	char **tokens = NULL;
	char *token = NULL;
	size_t token_count = 0;
	size_t bufsize = 0;

	if (input == NULL)
		return (NULL);

	/* Allocate initial memory for tokens array */
	tokens = malloc(sizeof(char *) * bufsize);
	if (tokens == NULL)
	{
		perror("Allocation error");
		exit(EXIT_FAILURE);
	}

	/* Tokenize the input */
	token = strtok(input, delimiter);
	while (token != NULL)
	{
		tokens = expand_tokens(tokens, token_count, &bufsize);

		tokens[token_count] = strdup(token);
		if (tokens[token_count] == NULL)
		{
			perror("Allocation error");
			exit(EXIT_FAILURE);
		}

		token_count++;

		token = strtok(NULL, delimiter);
	}

	tokens = expand_tokens(tokens, token_count, &bufsize);
	tokens[token_count] = NULL;

	return (tokens);
}
