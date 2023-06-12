#include "main.h"
#include <stdlib.h>

/**
 * read_textfile -  reads text file and prints it to the POSIX standard output
 * @filename: name of the file
 * @letters: number of letters
 * Return: the actual number of letters it could read and print
 *      0 if the file can not be opened or read
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t r, w;
	int fd;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	r = read(fd, buffer, letters);
	w = write(STDOUT_FILENO, buffer, r);

	free(buffer);
	close(fd);
	return (w);
}
