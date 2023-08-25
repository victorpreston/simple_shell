#include "main.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>

/**
 * tokenizer - function, inputs and stores the command
 *@input_string: shows to the input to be parsed
 *@delim: refers to the delimeter
 *
 *Return: returns the specific array of tokens
 */
char **tokenizer(char *input_string, char *delim)
{
	int num_delim = 0;
	char **av = NULL;
	char *token = NULL;
	char *save_ptr = NULL;

	token = _strtok_r(input_string, delim, &save_ptr);

	while (token != NULL)
	{
		av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
		av[num_delim] = token;
		token = _strtok_r(NULL, delim, &save_ptr);
		num_delim++;
	}

	av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
	av[num_delim] = NULL;

	return (av);
}

/**
 *print - func, prints a string to stdout
 *@string: this is the string to be printed

 *@stream: stream.
 *
 *Return: returns void
 */
void print(char *string, int stream)
{
	int i = 0;

	for (; string[i] != '\0'; i++)
		write(stream, &string[i], 1);
}


/**
 *remove_newline - scrapps off new lines

 *@str: shows the string to be used
 *
 *
 *Return: nothing
 */
void remove_newline(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	str[i] = '\0';
}


/**
 *_strcpy - cp a sring form a buffer to a nother buffer

 *@source: shows the source to be copied from
 *@dest: shows destination buffer to be copied to
 *
 * Return: nothing
 */
void _strcpy(char *source, char *dest)
{
	int i = 0;

	for (; source[i] != '\0'; i++)
		dest[i] = source[i];
	dest[i] = '\0';
}


/**
 *_strlen - counts the length of the string in program
 *@string: shows the string that is for counting
 *
 * Return: string length
 */
int _strlen(char *string)
{
	int len = 0;

	if (string == NULL)
		return (len);
	for (; string[len] != '\0'; len++)
		;
	return (len);
}
/************************Simple_Shell***************************/
