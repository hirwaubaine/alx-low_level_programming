#include <stdio.h>
#include "main.h"

/**
 * create_file - creates a file.
 * @filename: name of the file
 * @text_content: the content of the file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, n, w = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
	if (text_content != NULL)
	{
		for (n = 0; text_content[n]; n++)
			;
	}
	if (w == -1)
		return (-1);

	close(fd);
	return (1);
}
