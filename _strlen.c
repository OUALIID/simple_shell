#include "shell.h"

/**
 * _strlen -return (*s != '\0' ? _strlen_recursion(s + 1) + 1 : 0); }
 * @s: pointer.
 * Return: void.
 */
int _strlen(char *s)
{
	int len;

	if (*s != '\0')
		len = _strlen(s + 1) + 1;
	else
		len = 0;
	return (len);
}

