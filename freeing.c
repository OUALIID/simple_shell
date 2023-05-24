#include "shell.h"
/**
 * free_2D - check the code.
 * @array: a double pointer
 * Return: void.
 */
void free_2D(char **array)
{
	int i;

	i = 0;
	if (array == NULL)
		return;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}
