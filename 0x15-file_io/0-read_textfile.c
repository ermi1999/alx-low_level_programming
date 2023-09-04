#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * read_textfile - Reads a text file and prints it
 * to the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed. Returns 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, bytesRead, bytesWritten;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (0);
	}

	bytesRead = read(fd, buffer, letters);
	if (bytesRead == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);
	free(buffer);
	close(fd);

	if (bytesWritten == -1 || bytesWritten != bytesRead)
		return (0);

	return (bytesWritten);
}
