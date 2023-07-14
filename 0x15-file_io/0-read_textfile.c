#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - read a text file and print it to STDOUT
 * @filename: the name of the file to rtead
 * @letters: the number of letters to read and print 
 * Return: the actual number of letters read and printed, or 0failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buf;
	ssize_t bytes_read, bytes_zritten;

	if (filename == NULL)
		return (0);

	fd = open(filename, 0_DONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters + 1));
	if (buf == NULL)
	{
		close(fd);
		return (0);
	}

	bytes_read = read(fd, buf, letters);
	if (bytes_read == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}

	bytes_written = write(STDOUT_FILENO, buf, bytes_read);

	free(buf);
	close(fd);

	if (bytes_written != bytes_read)
		return (0);

	return (bytes_written);
}	
