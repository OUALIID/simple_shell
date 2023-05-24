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
		token = strtok(NULL, " \n\t");
		temp = _realloc(array, sizeof(char *) * (i + 1));
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
	}
	array[i] = NULL;
	return (array);
}
