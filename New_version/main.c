#include "shell.h"
/**
 * main - check the code.
 * Return: always 0.
 */
int main(void)
{
	signal(SIGINT, sigint_check);
	char *line = NULL, **array = NULL, *con;
	size_t len = 0;
	int i;

	i = 1;
	while (1)
	{
		printf("$ ");
		if (getline(&line, &len, stdin) == -1)
		{
			perror("getline error");
			exit(1);
		}
		if (line[0] == '\n')
			continue;
		if (spaces_tabs_check(line) == 0)
			continue;
		array = string_storage(line, i);
		if (clear_check(array) == 0)
			continue;
		exit_check(array);
		env_check(array);
		if (access(array[0], X_OK) == 0)
			execute_line(array[0], array);
		else
			path_finder(array);
		i = 1;
	}
	free(array);

	return (0);
}
