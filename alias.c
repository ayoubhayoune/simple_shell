#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * execute_alias - Execute the alias built-in command.
 * @tokens: Array of strings containing the command and its arguments.
 */
void execute_alias(char **tokens)
{
	if (tokens[1] == NULL)
	{
		/* Display all aliases */
		display_aliases();
	}
	else
	{
		/* Create or update an alias */
		create_alias(tokens);
	}
}

/**
 * display_aliases - Display all defined aliases.
 */
void display_aliases(void)
{
	/* Implement alias display functionality here */
	printf("Displaying all aliases\n");
}
/**
 * create_alias - Create or update an alias.
 *
 * @tokens: Array of strings containing the command and its arguments.
 */
void create_alias(char **tokens)
{
	char *alias_name, *alias_value;

	if (tokens == NULL || tokens[1] == NULL || tokens[2] == NULL)
	{
	fprintf(stderr, "alias: too few arguments\n");
	return;
	}

	alias_name = tokens[1];
	alias_value = tokens[2];

	/* Implement alias creation/update functionality here */
	printf("Creating or updating alias: %s='%s'\n", alias_name, alias_value);
}
