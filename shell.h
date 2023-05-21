#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/*INCLUDED FUNCTIONS*/

char **string_storage(char *line, int i);
char *path_finder(char **array);
void execute_line(char *con, char **array);

#endif
