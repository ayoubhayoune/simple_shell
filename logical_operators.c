#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * handle_logical_operators - Handle commands separated by && and ||.
 * @input: User input string.
 */
void handle_logical_operators(char *input)
{
	char *logical_operators[] = {"&&", "||"};
	char *token;
	char *saveptr;
	int prev_status = 0;

	token = strtok_r(input, " ", &saveptr);
	while (token != NULL)
	{
		int is_logical_operator = 0;

		int num_logical_operators =
		    sizeof(logical_operators) / sizeof(logical_operators[0]);
		for (int i = 0; i < num_logical_operators; i++)
		{
			if (strcmp(token, logical_operators[i]) == 0)
			{
				is_logical_operator = 1;
				break;
			}
		}

		if (is_logical_operator)
		{
			if (strcmp(token, "&&") == 0)
			{
				if (prev_status == 0)
				{
					execute_logical_operator(saveptr, "&&", &prev_status);
				}
			}
			else if (strcmp(token, "||") == 0)
			{
				if (prev_status != 0)
				{
					execute_logical_operator(saveptr, "||", &prev_status);
				}
			}
		}
		token = strtok_r(NULL, " ", &saveptr);
	}
}

/**
 * execute_logical_operator - Execute commands based on logical operators.
 * @input: User input string.
 * @operator: Logical operator ("&&" or "||").
 * @prev_status: Pointer to the previous command status.
 */
void execute_logical_operator(char *input, char *operator, int *prev_status)
{
	char *command;
	char *saveptr;
	int status;

	/* Get the next command after the logical operator */
	command = strtok_r(input, " ", &saveptr);

	/* Execute the command */
	process_command(command, &status);

	/* Update the previous command status */
	if (strcmp(operator, "&&") == 0)
	{
		/* && operator: Set status to 0 on success */
		*prev_status = (WIFEXITED(status) && WEXITSTATUS(status) == 0) ? 0 : 1;
	}
	else if (strcmp(operator, "||") == 0)
	{
		/* || operator: Set status to 0 on failure */
		*prev_status = (WIFEXITED(status) && WEXITSTATUS(status) != 0) ? 0 : 1;
	}
}
