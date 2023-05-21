#include "shell.h"
/**
 * path_finder - check the code.
 * @array: a double pointer
 * Return: double pointer.
 */
char *path_finder(char **array)
{
	char *path, *str, *con, *token;
	int size;

	path = getenv("PATH");
	size = strlen(path);
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
	{
		perror("ERROR");
		exit(1);
	}
	strcpy(str, path);
	token = strtok(str, ":");
	while (token != NULL)
	{
		con = malloc(sizeof(char) * (strlen(token) + strlen(array[0]) + 2));
		if (con == NULL)
		{
			perror("ERROR");
			exit(1);
		}
		strcpy(con, token);
		strcat(con, "/");
		strcat(con, array[0]);
		if (access(con, X_OK) == 0)
			break;
		token = strtok(NULL, ":");
	}
	return (con);
}
