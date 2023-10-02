#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define BUF_SIZE 1024

/**
 * main - Copies the content from one file to another
 * @argc: The argument count
 * @argv: The argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
int file_from, file_to;
char buffer[BUF_SIZE];
ssize_t bytes_read, bytes_written;
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
file_from = open(argv[1], O_RDONLY);
if (file_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}
file_to = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
if (file_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
exit(99);
}
while ((bytes_read = read(file_from, buffer, BUF_SIZE)) > 0)
{
bytes_written = write(file_to, buffer, bytes_read);
if (bytes_written != bytes_read || bytes_written == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
exit(99);
}
}
if (bytes_read == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}
if (close(file_from) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", file_from);
exit(100);
}
if (close(file_to) == -1)
{
dprintf(STDERR_FILENO, "Error: %d\n", file_to);
exit(100);
}
return (0);
}
