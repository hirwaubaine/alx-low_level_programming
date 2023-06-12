#include <stdio.h>
#include "main.h"

/**
 * open_file - checks if the file can open
 * @file_from: where the file is copied from
 * @file_to: where the file is copied to
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
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[2]);
		exit(99);
	}
}
/**
 * main - Copies the contents of a file to another file
 * @argc: The number of arguments
 * @argv: array of pointers to the arguments vector
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	char *buffer[1024];
	int file_from, file_to, close_file;
	ssize_t w, r;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}
	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	open_file(file_from, file_to, argv);

	r = 1024;
	while (r == 1024)
	{
		r = read(file_from, buffer, 1024);
		if (r == -1)
			open_file(-1, 0, argv);
		w = write(file_to, buffer, r);
		if (w == -1)
			open_file(-1, 0, argv);
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
