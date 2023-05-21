#include "shell.h"
/**
 * main - check the code.
 * Return: always 0.
 */
int main(void)
{
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
		array = string_storage(line, i);
		con = path_finder(array);
		execute_line(con, array);
		free(array);
		i = 1;
	}
	return (0);
}
