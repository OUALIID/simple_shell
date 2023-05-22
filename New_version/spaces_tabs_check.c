#include "shell.h"
/**
 * spaces_tabs_check - check the code.
 * @line: a pointer
 * Return: double pointer.
 */
int spaces_tabs_check(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else
			break;
	}
	if (i == _strlen(line) - 1)
		return (0);
	return (1);
}
