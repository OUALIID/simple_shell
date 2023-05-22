#include "shell.h"
/**
 * path_finder - check the code.
 * @array: a double pointer
 * Return: double pointer.
 */
void *path_finder(char **array)
{
	char *path, *str, *con, *token;
	int size;

	path = getenv("PATH");
	size = _strlen(path);
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
	{
		perror("ERROR");
		exit(1);
	}
	_strcpy(str, path);
	token = strtok(str, ":");
	while (token != NULL)
	{
		con = malloc(sizeof(char) * (_strlen(token) + _strlen(array[0]) + 2));
		if (con == NULL)
		{
			perror("ERROR");
			exit(1);
		}
		_strcpy(con, token);
		_strcat(con, "/");
		_strcat(con, array[0]);
		if (access(con, X_OK) == 0)
		{
			execute_line(con, array);
			break;
		}
		else
		{
			con = NULL;
			token = strtok(NULL, ":");
			continue;
		}
	}
	if (con == NULL)
		perror(array[0]);
	free(con);
	free(str);
}
