#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

/**
 * error_exit - Print an error message and exit.
 * @msg: Message to print before error.
 * @code: Exit status code.
 */
void error_exit(const char *msg, int code)
{
fprintf(stderr, "%s: %s\n", msg, strerror(errno));
exit(code);
}

/**
 * main - Displays information contained in ELF header at start of an ELF file
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char **argv)
{
int fd, rc;
void *addr;
struct stat st;
Elf64_Ehdr *header;
char magic[] = {0x7f, 'E', 'L', 'F', '\0'};
if (argc != 2)
{
fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
return (98);
}
fd = open(argv[1], O_RDONLY);
if (fd == -1)
error_exit("Error: Cannot open file", 98);
rc = fstat(fd, &st);
if (rc == -1)
error_exit("Error: Cannot get file size", 98);
addr = mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
if (addr == MAP_FAILED)
error_exit("Error: Cannot read from file", 98);
header = addr;
if (memcmp(header->e_ident, magic, sizeof(magic)) != 0)
{
fprintf(stderr, "Error: %s is not an ELF file\n", argv[1]);
return (98);
}
printf("Magic:   ");
for (rc = 0; rc < EI_NIDENT; rc++)
printf("%02x%c", header->e_ident[rc], rc == EI_NIDENT - 1 ? '\n' : ' ');
printf("Class:    %s\n", header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "Invalid Class");
printf("Data:   %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "Invalid data encoding");
printf("Version:     %d (Current)\n", header->e_ident[EI_VERSION]);
printf("OS/ABI:   ");
switch (header->e_ident[EI_OSABI])
{
case ELFOSABI_SYSV:
printf("UNIX System V ABI\n");
break;
case ELFOSABI_HPUX:
printf("HP-UX ABI\n");
break;
case ELFOSABI_NETBSD:
printf("NetBSD ABI\n");
break;
case ELFOSABI_LINUX:
printf("Linux ABI\n");
break;
case ELFOSABI_SOLARIS:
printf("Sun Solaris ABI\n");
break;
case ELFOSABI_IRIX:
printf("SGI Irix ABI\n");
break;
case ELFOSABI_FREEBSD:
printf("FreeBSD ABI\n");
break;
case ELFOSABI_TRU64:
printf("Compaq TRU64 UNIX ABI\n");
break;
case ELFOSABI_ARM:
printf("ARM architecture ABI\n");
break;
case ELFOSABI_STANDALONE:
printf("Stand-alone (embedded) ABI\n");
break;
default:
printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
}
printf("ABI Version:     %d\n", header->e_ident[EI_ABIVERSION]);
printf("Type:      ");
switch (header->e_type)
{
case ET_NONE:
printf("NONE (None)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYNAMIC (Shared object file)\n");
break;
default:
printf("<unknown: %x>\n", header->e_type);
}
printf("Entry point address:    %lx\n", (unsigned long)header->e_entry);
printf("Start of program headers:   %ld (bytes into file)\n", (long)header->e_phoff);
printf("Start of section headers:  %ld (bytes into file)\n", (long)header->e_shoff);
printf("Flags:     %ld\n", (long)header->e_flags);
printf("Size of this header:   %d (bytes)\n", header->e_ehsize);
printf("Size of program headers:  %d (bytes)\n", header->e_phentsize);
printf("Number of program headers:  %d\n", header->e_phnum);
printf("Size of section headers:  %d (bytes)\n", header->e_shentsize);
printf("Number of section headers:   %d\n", header->e_shnum);
printf("Section header string table index: %d\n", header->e_shstrndx);
rc = munmap(addr, st.st_size);
if (rc == -1)
error_exit("Error: Cannot munmap file", 98);
rc = close(fd);
if (rc == -1)
error_exit("Error: Cannot close file", 98);
return (0);
}
