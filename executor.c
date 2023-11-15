#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * execute_command - Execute a command with its arguments.
 *
 * @tokens: Array of strings containing the command and its arguments.
 */
void execute_command(char **tokens)
{
	pid_t pid, wpid;
	int status;

	if (tokens == NULL || tokens[0] == NULL)
		return; /* Empty command, do nothing */

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execvp(tokens[0], tokens) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Forking error");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
