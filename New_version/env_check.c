#include "shell.h"
/**
 * env_check - check the code.
 * @array: a double pointer
 * Return: double pointer.
 */
void env_check(char **array)
{
	if (_strlen(array[0]) == _strlen("env") && _strcmp(array[0], "env") == 0)
		for (int j = 0; environ[j] != NULL; j++)
			printf("%s\n", environ[j]);
}
