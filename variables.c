#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * handle_variables - Handle variables replacement in a command.
 * @input: User input string.
 * Return: Command string with variables replaced.
 */
char *handle_variables(char *input)
{
	char *result = strdup(input);

	char *variable __attribute__((unused));

	/* Handle $? variable */
	if (strstr(result, "$?") != NULL)
	{
		int exit_status = get_exit_status();
		char exit_status_str[4];

		sprintf(exit_status_str, "%d", exit_status);

		/* Replace $? with the exit status */
		result = replace_string(result, "$?", exit_status_str);
	}

	/* Handle $$ variable */
	if (strstr(result, "$$") != NULL)
	{
		pid_t shell_pid = getpid(); /* Get the process ID of the shell */
		char shell_pid_str[10]; /* Assumes PID is a 9-digit number or less */

		sprintf(shell_pid_str, "%d", shell_pid);

		/* Replace $$ with the shell's process ID */
		result = replace_string(result, "$$", shell_pid_str);
	}

	return (result);
}

/**
 * get_exit_status - Get the exit status of the last command.
 * Return: Exit status.
 */
int get_exit_status(void)
{
	printf("Getting exit status\n");
	return (0);
}

/**
 * replace_string - Replace all occurrences of a substring in a string.
 * @str: The string to modify.
 * @old_str: The substring to replace.
 * @new_str: The replacement substring.
 * Return: Modified string.
 */
char *replace_string(char *str, const char *old_str, const char *new_str)
{
	char *result;
	int i, cnt = 0;
	int new_str_len = strlen(new_str);
	int old_str_len = strlen(old_str);

	/* Count the number of occurrences of old_str in str */
	for (i = 0; str[i] != '\0'; ++i)
	{
		if (strstr(&str[i], old_str) == &str[i])
		{
			++cnt;
			i += old_str_len - 1;
		}
	}

	/* Allocate memory for the modified string */
	result = (char *)malloc(i + cnt * (new_str_len - old_str_len) + 1);

	i = 0;
	while (*str)
	{
		/* Check if the substring is at the current position */
		if (strstr(str, old_str) == str)
		{
			strcpy(&result[i], new_str);
			i += new_str_len;
			str += old_str_len;
		}
		else
		{
			result[i++] = *str++;
		}
	}

	result[i] = '\0'; /* Null-terminate the modified string */

	return (result);
}
