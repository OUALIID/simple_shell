#include "shell.h"
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
