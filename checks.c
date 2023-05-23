#include "shell.h"
/**
 * env_check - check the code.
 * @array: a double pointer
 * Return: double pointer.
 */
void env_check(char **array)
{
	int j, l;

	if (_strlen(array[0]) == _strlen("env") && _strcmp(array[0], "env") == 0)
		for (j = 0; environ[j] != NULL; j++)
		{
			for (l = 0; environ[j][l] != '\0'; l++)
				_putchar(environ[j][l]);
			_putchar('\n');
		}
}
/**
 * clear_check - check the code.
 * @array: a double pointer
 * Return: double pointer.
 */
int clear_check(char **array)
{
	if (_strlen(array[0]) == _strlen("clear") && _strcmp(array[0], "clear") == 0)
	{
		system("clear");
		return (0);
	}
	return (1);
}
/**
 * exit_check - check the code.
 * @array: a double pointer
 * @line: a pointer
 * Return: void.
 */
void exit_check(char **array, char *line)
{
	int tmp;

	if (_strlen(array[0]) == _strlen("exit") && _strcmp(array[0], "exit") == 0)
	{
		if (array[1] != NULL)
		{
			tmp = atoi(array[1]);
			free(array);
			free(line);
			exit(tmp);
		}
		else
		{
			free(array);
			free(line);
			exit(0);
		}
	}
}
/**
 * spaces_tabs_check - check the code.
 * @line: a pointer
 * Return: double pointer.
 */
int spaces_tabs_check(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else
			break;
	}
	if (i == _strlen(line) - 1)
		return (0);
	return (1);
}
