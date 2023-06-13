#include <stdio.h>
#include "main.h"

/**
 * open_file - checks if a file can open
 * @file_from: where file is copied from
 * @file_to: where file is copied to
 * @argv: array of pointers to the arguments vector
 * Return: no return
 */
void open_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}
/**
 * main - Copies the contents of a file to another file.
 * @argv: array of pointers to the arguments vector
 * @argc: number of arguments
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, close_file;
	ssize_t n, r;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	open_file(file_from, file_to, argv);

	n = 1024;
	while (n == 1024)
	{
		n = read(file_from, buffer, 1024);
		if (n == -1)
			open_file(-1, 0, argv);
		r = write(file_to, buffer, n);
		if (r == -1)
			open_file(0, -1, argv);
	}

	close_file = close(file_from);
	if (close_file == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	close_file = close(file_to);
	if (close_file == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		exit(100);
	}
	return (0);
}
