#include "shell.h"

/**
 * _realloc - check the code.
 * @ptr: pointer
 * @size : variable.
 * Return: pointer.
 */
void *_realloc(void *ptr, unsigned int size)
{
	char *new_ptr;
	unsigned int i, newest;

	if (ptr == NULL)
	{
		ptr = malloc(size);
		return (ptr);
	}
	if (size > sizeof(ptr))
		newest = sizeof(ptr);
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size);
	if (new_ptr == NULL)
	{
		perror("ERROR");
		exit(1);
	}
	for (i = 0; i < newest; i++)
		new_ptr[i] = ((char *)ptr)[i];
	free(ptr);
	return (new_ptr);
}
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
