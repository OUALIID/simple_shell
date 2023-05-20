#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * main - First version of the code
 * Return: int.
 */
int main(void)
{
	char *line = NULL, **array = NULL;
	size_t len = 0;
	int i, status, read;

	i = 1;
	while (1)
	{
		printf("$ ");
		/* READ INPUT */
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			perror("getline error");
			exit(1);
		}
		/* IN CASE INPUT WAS ONLY A NEW LINE THE PROGRAM SHOULD CONTINUE */
		if (line[0] == '\n')
			continue;

		/* STRTOK FOR THE LINE */
		char *token = strtok(line, " \n\t");

		/* STORING THE STRINGS INSIDE AN ARRAY */
		array = malloc(sizeof(char *) * i);
		if (array == NULL)
		{
			perror("ERROR");
			exit(1);
		}
		array[0] = token;
		while (token != NULL)
		{
			token = strtok(NULL, " \n\t");
			array[i] = token;
			i++;
			array = realloc(array, sizeof(char *) * (i + 1));
			if (array == NULL)
			{
				perror("ERROR");
				exit(1);
			}
		}
		array[i] = NULL;

		/* FORK */
		pid_t pid = fork();
		if (pid == -1)
		{
			perror("ERROR");
			exit(1);
		}
		if (pid == 0)
		{
			execve(array[0], array, NULL);
			perror("ERROR");
			exit(1);
		}
		else
			wait(&status);

		free(array);
		i = 1;
	}
	return (0);
}
