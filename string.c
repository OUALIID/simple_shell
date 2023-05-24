#include "shell.h"
/**
 * _putchar - check the code
 * @c: a variable.
 * Return: Always 0 (Success)
 */
int _putchar(char c)
{
	write(1, &c, 1);
	return (0);
}
/**
 * _strcat - check the code
 * @dest: pointer destination
 * @src: pointer source
 * Return: void.
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcpy - check the code
 * @dest: pointer
 * @src: pointer
 * Return: void.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		*(dest + i) = *(src + i);
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcmp - check the code
 * @s1: pointer destination
 * @s2: pointer source
 * Return: void.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}
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
