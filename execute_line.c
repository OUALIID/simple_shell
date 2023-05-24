#include "shell.h"
/**
 * execute_line - check the code.
 * @con: a pointer
 * @array: a double pointer
 * Return: double pointer.
 */
int execute_line(char *con, char **array)
{
	int exit_stat = 0;
	int status;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("ERROR");
		exit(1);
	}
	if (pid == 0)
	{
		execve(con, array, NULL);
		perror(array[0]);
		exit(errno);
	}
	else
	{
		wait(&status);
		exit_stat = WEXITSTATUS(status);
	}
	return (exit_stat);
}
