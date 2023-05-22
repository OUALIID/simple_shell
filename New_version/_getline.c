#include "shell.h"
/**
 * _getchar - check the code
 * Return: int.
 */
char _getchar(void)
{
	char c;
	ssize_t to_read;

	to_read = read(STDIN_FILENO, &c, 1);
	if (to_read == 1)
		return (c);
	else
		return (EOF);
}
/**
 * _getline - check the code
 * @line: double pointer
 * @len: size_t variable
 * @stream: File stream
 * Return: size_t.
 */
ssize_t _getline(char **line, size_t *len, FILE *stream)
{
	char *buffer = NULL, *new_buffer;
	size_t buffer_size = 0, chars_read = 0;
	char c;

	if (line == NULL || len == NULL || stream == NULL)
		return (-1);
	if (*line == NULL)
	{
		*line = malloc(*len);
		if (*line == NULL)
			return (-1);
	}
	buffer = *line;
	buffer_size = *len;
	while ((c = _getchar()) != EOF)
	{
		if (chars_read + 1 >= buffer_size)
		{
			buffer_size += 128;
			new_buffer = realloc(buffer, buffer_size);
			if (new_buffer == NULL)
			{
				free(buffer);
				return (-1);
			}
			buffer = new_buffer;
		}
		buffer[chars_read++] = c;
		if (c == '\n')
			break;
	}
	if (chars_read == 0)
	{
		free(buffer);
		return (-1);
	}
	buffer[chars_read] = '\0';
	*line = buffer;
	*len = buffer_size;
	return (chars_read);
}
