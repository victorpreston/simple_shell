#ifndef __SHELL_H
#define __SHELL_H

/**********************HEADER FILE***************************/
/**
 * File_name: __SHELL_H
 * Auth:`victorpreston` & `Mmjosh`
 *
 */

#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <string.h>


/*alx-simple_shell constants*/
#define INVALID_COMMAND -1
#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3

/*define prompts*/
#define min(x, y) (((x) < (y)) ? (x) : (y))

/**funcs**/
/**
 *struct map: - matches/maps a command to a function
 *
 *
 *@command_name: name used to identify a command
 *@func: executes the command
 *
 * ALX PROJECTS
 */
typedef struct map
{
	char *command_name;
	void (*func)(char **command);
} function_map;


/** global history_counter **/
int hist;

/** global_environemnt **/
extern char **environ;

/** global name of program **/
char *name;

/*** global linked lists and aliases ***/
alias_t *aliases;

/***extern global****/
extern char **environ;
extern char *line;
extern char **commands;
extern char *shell_name;
extern int status;


/**Helpers_1**/
void remove_newline(char *);
int _strlen(char *);
void _strcpy(char *, char *);
void print(char *, int);
char **tokenizer(char *, char *);

/**Helpers_2**/
int _strcspn(char *, char *);
char *_strchr(char *, char);
int _strcmp(char *, char *);
char *_strcat(char *, char *);
int _strspn(char *, char *);

/**Helpers_3**/
void ctrl_c_handler(int);
void remove_comment(char *);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strtok_r(char *, char *, char **);
int _atoi(char *);

/**Utilities**/
char *check_path(char *);
void (*get_func(char *))(char **);
char *_getenv(char *);
int parse_command(char *);
void execute_command(char **, int);

/**Buletins**/
void quit(char **);
void env(char **);

/**Main_funcs**/
extern void initializer(char **current_command, int type_command);
extern void non_interactive(void);
#endif

/********************HEADER FILE************************/
