#include "shell.h"
#include <stdio.h>

	char **commands = NULL;
	char *line = NULL;
	char *shell_name = NULL;
	int status = 0;

/************Simple_Shell************/
/**
 * main - This is the Simple_Shell Main Code
 * @argc: arguments passed in program
 * @argv: arguments inj the programm yet to be parsed
 *
 * Applies the funcs in both helpers and program utils
 * Implements the EOF
 * Return: 0 on when the program is success
 * Prints error in the case of failure in program
 *
 * Simple_Shell
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char **current_command = NULL;
	int i, type_command = 0;
	size_t n = 0;

	signal(SIGINT, ctrl_c_handler);
	shell_name = argv[0];
	while (1)
	{
		non_interactive();
		print(" ($) ", STDOUT_FILENO);
		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(status);
		}
			remove_newline(line);
			remove_comment(line);
			commands = tokenizer(line, ";");

		for (i = 0; commands[i] != NULL; i++)
		{
			current_command = tokenizer(commands[i], " ");
			if (current_command[0] == NULL)
			{
				free(current_command);
				break;
			}
			type_command = parse_command(current_command[0]);

			/* initializer -   */
			initializer(current_command, type_command);
			free(current_command);
		}
		free(commands);
	}
	free(line);

	return (status);
}
/************Simple_Shell**********/
