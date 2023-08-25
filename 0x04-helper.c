#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>

/*************Simple_Shell******************/
/**
 *
 *_strtok_r - function: tokenizes a string in the program
 *@string: shows the string
 *@delim: delimiter: tokenizer
 *@save_ptr: pointer: keeps tracks of the tokens
 *
 *Return: returns next token in line for tokenization
 *
 */
char *_strtok_r(char *string, char *delim, char **save_ptr)
{
	char *finish;

	if (string == NULL)
		string = *save_ptr;

	if (*string == '\0')
	{
		*save_ptr = string;
		return (NULL);
	}

	string += _strspn(string, delim);
	if (*string == '\0')
	{
		*save_ptr = string;
		return (NULL);
	}

	finish = string + _strcspn(string, delim);
	if (*finish == '\0')
	{
		*save_ptr = finish;
		return (string);
	}

	*finish = '\0';
	*save_ptr = finish + 1;
	return (string);
}


/**
 * _atoi - function: changes a string to an interger
 *
 * @s: shows the string to be effected by _atoi
 *
 * Return:returns the resulting integer
 */
int _atoi(char *s)
{
	unsigned int n = 0;

	do {
		if (*s == '-')
			return (-1);
		else if ((*s < '0' || *s > '9') && *s != '\0')
			return (-1);
		else if (*s >= '0'  && *s <= '9')
			n = (n * 10) + (*s - '0');
		else if (n > 0)
			break;
	} while (*s++);
	return (n);
}


/**
 * _realloc - function: re allocated the memmory
 *
 * @ptr: shows previously allocated memmory
 * @old_size: function: size of pointer
 * @new_size: function: shows the new size of memmory
 *
 * Return: returns memmory address
 *
 *
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *temp_block;
	unsigned int i;

	if (ptr == NULL)
	{
		temp_block = malloc(new_size);
		return (temp_block);
	}
	else if (new_size == old_size)
		return (ptr);
	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		temp_block = malloc(new_size);
		if (temp_block != NULL)
		{
			for (i = 0; i < min(old_size, new_size); i++)
				*((char *)temp_block + i) = *((char *)ptr + i);
			free(ptr);
			return (temp_block);
		}
		else
			return (NULL);

	}
}


/**
 * ctrl_c_handler - function: handles the signal [CTRL + C]
 *
 * @signum:shows the number of the signal
 *
 * Return: nothing
 */
void ctrl_c_handler(int signum)
{
	if (signum == SIGINT)
		print("\n($) ", STDIN_FILENO);
}


/**
 * remove_comment -function: ignores what is a comment
 *
 * @input: shows the intended input
 *
 * Return: nothing
 *
 */
void remove_comment(char *input)
{
	int i = 0;

	if (input[i] == '#')
		input[i] = '\0';
	while (input[i] != '\0')
	{
		if (input[i] == '#' && input[i - 1] == ' ')
			break;
		i++;
	}
	input[i] = '\0';
}
/**********************Simple_shell**************************/
