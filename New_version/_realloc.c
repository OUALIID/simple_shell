#include "shell.h"

/**
 * _realloc - check the code.
 * @ptr: pointer
 * @size : variable.
 * Return: pointer.
 */
#include <stdlib.h>

void *_realloc(void *ptr, size_t size)
{
	void **new_ptr;
	size_t i;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		ptr = malloc(size);
		return (ptr);
	}
	new_ptr = malloc(size);
	if (new_ptr == NULL)
	{
		perror("ERROR");
		exit(1);
	}
	for (i = 0; i < size / sizeof(void *); i++)
	{
		new_ptr[i] = ((void **)ptr)[i];
	}
	free(ptr);
	return (new_ptr);
}
