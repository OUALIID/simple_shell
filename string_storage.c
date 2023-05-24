#include "shell.h"
/**
 * string_storage - check the code.
 * @line: a pointer
 * Return: double pointer.
 */
char **string_storage(char *line)
{
	char *token;
	char **array;
	int i;

	i = 0;
	token = strtok(line, " \n\t");
	array = malloc(sizeof(char *) * 2);
	array[0] = NULL;
	array[1] = NULL;
	if (array == NULL)
	{
		perror("ERROR");
		return (NULL);
	}
	while (token != NULL)
	{
		array = realloc(array, sizeof(char *) * (i + 2));
		if (array == NULL)
		{
			perror(array[0]);
			free(line);
			exit(1);
		}
		array[i] = strdup(token);
		token = strtok(NULL, " \n\t");
		i++;
	}
	array[i] = NULL;
	return (array);
}
