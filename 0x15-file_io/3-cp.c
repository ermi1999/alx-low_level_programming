#include "main.h"

/**
 * open_files - Open source and destination files
 * @file_from: Name of the source file
 * @file_to: Name of the destination file
 *
 * Return: File descriptor of the opened file
 */
int open_files(char *file_from)
{
	int fd = open(file_from, O_RDONLY);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	return (fd);
}

/**
 * close_files - Close file descriptors
 * @fd_from: File descriptor of the source file
 * @fd_to: File descriptor of the destination file
 */
void close_files(int fd_from, int fd_to)
{
	int ret;

	ret = close(fd_from);
	if (ret == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}

	ret = close(fd_to);
	if (ret == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}
}

/**
 * copy_file - Copy the contents from source file to destination file
 * @fd_from: File descriptor of the source file
 * @fd_to: File descriptor of the destination file
 */
void copy_file(int fd_from, int fd_to)
{
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file\n");
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file\n");
		exit(98);
	}
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 97-100 on error
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	fd_from = open_files(argv[1]);
	fd_to = open_files(argv[2]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
		exit(99);
	}

	copy_file(fd_from, fd_to);
	close_files(fd_from, fd_to);

	return (0);
}
