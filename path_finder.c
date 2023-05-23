#include "shell.h"
/**
 * path_finder - check the code.
 * @array: a double pointer
 * Return: double pointer.
 */
void path_finder(char **array)
{
	char *path = getenv("PATH"), *str, *con, *token;

	str = malloc(sizeof(char) * (_strlen(path) + 1));
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
			free(str);
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
			free(con);
			con = NULL;
			token = strtok(NULL, ":");
			continue;
		}
		free(con);
	}
	if (con == NULL)
		perror(array[0]);
	free(con);
	free(str);
}
