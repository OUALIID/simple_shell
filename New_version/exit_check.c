#include "shell.h"
/**
 * exit_check - check the code.
 * @array: a double pointer
 * Return: void.
 */
void exit_check(char **array)
{
	int tmp;

	if (_strlen(array[0]) == _strlen("exit") && _strcmp(array[0], "exit") == 0)
	{
		if (array[1] != NULL)
		{
			tmp = atoi(array[1]);
			exit(tmp);
		}
		else
			exit(0);
	}
}
