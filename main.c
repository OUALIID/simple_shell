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
	char *line = NULL;
	size_t len = 0;
	int is_interactive = isatty(STDIN_FILENO);
	char **array;

	while (1)
	{
		if (is_interactive)
			_putchar_cisfun();
		if (getline(&line, &len, stdin) == -1)
		{
			if (is_interactive)
				perror("getline error");
			break;
		}
		if (line[0] != '\n' && spaces_tabs_check(line))
		{
			array = string_storage(line);
			if (clear_check(array))
			{
				exit_check(array, line);
				env_check(array);
				if (access(array[0], X_OK) == 0)
					execute_line(array[0], array);
				else
					path_finder(array);
			}
			free(array);
		}
		free(line);
		line = NULL;
	}
	return (0);
}
