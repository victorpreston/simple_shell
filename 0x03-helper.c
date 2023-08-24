#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

/****************Simple_Shell******************/
/**
 *_strcmp - func, compares 2 or more strings
 *@first: sting compared at the beginning
 *@second: 2nd Compared String
 *
 * Return: Returns the difference in the strings comapred
 */
int _strcmp(char *first, char *second)
{
	int i = 0;

	while (first[i] != '\0')
	{
		if (first[i] != second[i])
			break;
		i++;
	}
	return (first[i] - second[i]);
}

/**
 *_strcat - concatenation of 2 strs

 *@destination:shows the  str to_be_concatnated
 *@source:shows the str to_concatenate
 *
 * Return:returns address of the new concatnated string
 */

char *_strcat(char *destination, char *source)
{
	char *new_string =  NULL;
	int len_dest = _strlen(destination);
	int len_source = _strlen(source);

	new_string = malloc(sizeof(*new_string) * (len_dest + len_source + 1));
	_strcpy(destination, new_string);
	_strcpy(source, new_string + len_dest);
	new_string[len_dest + len_source] = '\0';
	return (new_string);
}



/**
 *_strspn - spans the string

 *@str1: shows on the string to be searched
 *@str2: func, shows the string to be used
 *
 *Return: returns no. of bytes
 */
int _strspn(char *str1, char *str2)
{
	int i = 0;
	int match = 0;

	while (str1[i] != '\0')
	{
		if (_strchr(str2, str1[i]) == NULL)
			break;
		match++;
		i++;
	}
	return (match);
}


/**
 *_strcspn - func to compute segments in string cocatnation

 *@str1: seraches for the specific sting

 *@str2: shows the string to be used
 *
 *Return: returns index
 */
int _strcspn(char *str1, char *str2)
{
	int len = 0, i;

	for (i = 0; str1[i] != '\0'; i++)
	{
		if (_strchr(str2, str1[i]) != NULL)
			break;
		len++;
	}
	return (len);
}






/**
 *_strchr - fnction: locates the character [char] in string.
 *
 *@s: shows the string to be used for character searching
 *@c: shows the character to be located in the string
 *
 *
 *Return: this is a pointer
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] != c && s[i] != '\0'; i++)
		;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}
/****************************Simple_Shell*****************/
