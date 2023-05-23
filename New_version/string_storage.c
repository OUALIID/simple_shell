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

	i = 1;
	token = strtok(line, " \n\t");
	array = malloc(sizeof(char *) * i);
	if (array == NULL)
	{
		perror("ERROR");
		exit(1);
	}
	array[0] = token;
	while (token != NULL)
	{
		token = strtok(NULL, " \n\t");
		array[i] = token;
		i++;
		array = _realloc(array, sizeof(char *) * (i + 1));
		if (array == NULL)
		{
			perror("ERROR");
			exit(1);
		}
	}
	array[i] = NULL;
	return (array);
}
