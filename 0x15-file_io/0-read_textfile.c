#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the name of the file to read.
 * @letters: the number of letters to read and print.
 *
 * Return: the actual number of letters read and printed.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
ssize_t n_read, n_written;
char *buf;
int fd;
if (filename == NULL)
return (0);
fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);
buf = malloc(sizeof(char) * letters);
if (buf == NULL)
{
close(fd);
return (0);
}
n_read = read(fd, buf, letters);
if (n_read == -1)
{
close(fd);
free(buf);
return (0);
}
n_written = write(STDOUT_FILENO, buf, n_read);
if (n_written == -1 || n_written != n_read)
{
close(fd);
free(buf);
return (0);
}
close(fd);
free(buf);
return (n_written);
}
