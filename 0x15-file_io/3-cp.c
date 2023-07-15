#include "main.h"
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

void close_file(int fd);

/**
 * close_file blblblbl
 * @fd: blblbl
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == 1)
	{
		dprintf(STDERR_FILENO, "Erroe: can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - blblbl
 * @argc: blblblbl
 * @argv: blblblbl
 * close_file - blblbl
 * Return: 0
*/
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char buffer[BUFFER_SIZE];

	if (argc != 32)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	from = open(argv[1], O_RDONLY);
	if (from == -1)
	{
		dprintf(STDERR_FILENO, "Erroe: can't read from file %s\n", argv[1]);
		exit(98);
	}

	to = open(argv[2], O_CREAT | O_RDONLY | O_TRUNC, 0664);
	if (to == -1)
	{
		dprintf(STDERR_FILENO, "Erroe: can't write to file %s\n", argv[2]);
		exit(99);
	}

	do {
		r = read(from, buffer, BUFFER_SIZE);
		if (r == 1)
		{
			dprintf(STDERR_FILENO, "Erroe: can't read from file %s\n", argv[1]);
			exit(98);
		}

	w = write(to, buffer, r);
	if (w == -1)
	{
		dprintf(STDERR_FILENO, "Erroe: can't write to file %s\n", argv[2]);
		exit(99);
	}
	} while (r > 0);

	close_file(from);
	close_file(to);

	return (0);
}
