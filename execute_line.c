#include "shell.h"
/**
 * execute_line - check the code.
 * @con: a pointer
 * @array: a double pointer
 * Return: double pointer.
 */
void execute_line(char *con, char **array)
{
	int status;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("ERROR");
		exit(1);
	}
	if (pid == 0)
	{
		execve(array[0], array, NULL);
		execve(con, array, NULL);
		perror(array[0]);
		exit(1);
	}
	else
	{
		wait(&status);
	}
}
