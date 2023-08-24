#include "shell.h"
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>

/**************Simple_Shell**************/
/**
 * initializer -function: intializes execution
 * @current_command: checks the recent or current command
 *
 * @type_command: shows the type command parse token
 *
 * Return: nothing
 */

void initializer(char **current_command, int type_command)
{
	pid_t PID;

	if (type_command == EXTERNAL_COMMAND || type_command == PATH_COMMAND)
	{
		PID = fork();
		if (PID == 0)
			execute_command(current_command, type_command);
		else
		{
			waitpid(PID, &status, 0);
			status >>= 8;
		}
	}
	else
		execute_command(current_command, type_command);
}
/**********Simple_Shell**************/
