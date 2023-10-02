#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - appends text to the end of a file.
 * @filename: the name of the file to append to.
 * @text_content: the content to append to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
int fd, len, n_written;
if (filename == NULL)
return (-1);
fd = open(filename, O_WRONLY | O_APPEND);
if (fd == -1)
return (-1);
if (text_content != NULL)
{
for (len = 0; text_content[len] != '\0'; len++)
{
;
}
n_written = write(fd, text_content, len);
if (n_written == -1 || n_written != len)
{
close(fd);
return (-1);
}
}
close(fd);
return (1);
}
