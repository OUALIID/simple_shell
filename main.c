#include "shell.h"
/**
 * _putchar_cisfun - check the code.
 * Return: void.
 */
void _putchar_cisfun(void)
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
/**
 * main - check the code.
 * Return: always 0.
 */
int main(void)
{
	char *line;
	size_t len = 0;
	char **array;
	int is_interactive = isatty(STDIN_FILENO);

	line = NULL;
	while (1)
	{
		if (is_interactive)
			_putchar_cisfun();
		if (_getline(&line, &len, stdin) == -1)
		{
			if (is_interactive)
			{
				perror("getline error");
				free(line);
				exit(EXIT_SUCCESS);
			}
			break;
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
	return 0;
}
