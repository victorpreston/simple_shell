#include "main.h"



/**
  * _unsetenv - deletes a value from the environment.
  * @name: name of key=value pair to delete
  * Return: Success or failure
  */
int _unsetenv(const char *name)
{
	return (unsetenv(name));
}
/**
  * _setenv - adds or modifies a value from the environment.
  * @name: name of key=value pair
  * @value: value of the key=value pair
  * @overwrite: flag to determine whether to update if key exists
  * Return: 0 on success or -1 on failure
  */
int _setenv(const char *name, const char *value, int overwrite)
{
	return (setenv(name, value, overwrite));
}
