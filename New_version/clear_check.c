#include "shell.h"
/**
 * clear_check - check the code.
 * @array: a double pointer
 * Return: double pointer.
 */
int clear_check(char **array)
{
	if (_strlen(array[0]) == _strlen("clear") && strcmp(array[0], "clear") == 0)
	{
		system("clear");
		return (0);
	}
	return (1);
}
