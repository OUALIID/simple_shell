#include "shell.h"
/**
 * main - check the code.
 * Return: always 0.
 */
int main(void)
{
	signal(SIGINT, sigint_check);
	char *line = NULL, **array;
	size_t len = 0;

	while (1)
	{
		_putchar('$');
		_putchar(' ');
		fflush(stdout);
		if (_getline(&line, &len, stdin) == -1)
		{
			perror("getline error");
			exit(1);
		}
		if (line[0] == '\n' || spaces_tabs_check(line) == 0)
		{
			free(line);
			line = NULL;
			continue;
		}
		array = string_storage(line);
		if (clear_check(array) == 0)
		{
			free(line);
			line = NULL;
			free(array);
			continue;
		}
		exit_check(array, line);
		env_check(array);
		if (access(array[0], X_OK) == 0)
			execute_line(array[0], array);
		else
			path_finder(array);
		free(line);
		line = NULL;
		free(array);
	}
	return (0);
}
