#include "shell.h"
/**
 * main - check the code.
 * Return: always 0.
 */

void _putchar_cisfun()
{
	_putchar('#');
	_putchar('c');
	_putchar('i');
	_putchar('s');
	_putchar('f');
	_putchar('u');
	_putchar('n');
	_putchar('$');
	_putchar(' ');
}
int main(void)
{
	char *line, **array;
	size_t len = 0;

	line = NULL;
	while (1)
	{
		_putchar_cisfun();
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
