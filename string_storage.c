#include "shell.h"
/**
 * string_storage - check the code.
 * @line: a pointer
 * Return: double pointer.
 */
char **string_storage(char *line)
{
	char *token;
	char **array, **temp;
	int i;

	i = 1;
	token = strtok(line, " \n\t");
	array = malloc(sizeof(char *) * i);
	if (array == NULL)
	{
		perror("ERROR");
		return (NULL);
	}
	array[0] = token;
	while (token != NULL)
	{
		temp = _realloc(array, sizeof(char *) * (i + 2));
		if (temp == NULL)
		{
			perror(array[0]);
			free(line);
			exit(1);
		}
		array = temp;
		i++;
		if (array == NULL)
		{
			perror(array[0]);
			free(line);
			exit(1);
		}
		token = strtok(NULL, " \n\t");
	}
	array[i] = NULL;
	return (array);
}
