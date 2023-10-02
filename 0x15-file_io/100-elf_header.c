#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "main.h"

/**
 * error_exit - print an error message and exit with failure status code.
 * @msg: the error message to print.
 */
void error_exit(char *msg)
{
fprintf(stderr, "%s\n", msg);
exit(98);
}

/**
 * print_elf_magic - prints the ELF magic numbers from the ELF header.
 * @h: a pointer to the ELF header.
 */
void print_elf_magic(Elf32_Ehdr *h)
{
int i;
printf("  Magic:   ");
for (i = 0; i < EI_NIDENT; i++)
{
printf("%02x ", h->e_ident[i]);
}
printf("\n");
}

/**
 * print_elf_class - prints the ELF class from the ELF header.
 * @h: a pointer to the ELF header.
 */
void print_elf_class(Elf32_Ehdr *h)
{
printf("Class:     ");
if (h->e_ident[EI_CLASS] == ELFCLASSNONE)
printf("none\n");
else if (h->e_ident[EI_CLASS] == ELFCLASS32)
printf("ELF32\n");
else if (h->e_ident[EI_CLASS] == ELFCLASS64)
printf("ELF64\n");
else
printf("<unknown: %x>\n", h->e_ident[EI_CLASS]);
}

/**
 * print_elf_data - prints the ELF data encoding from the ELF header.
 * @h: a pointer to the ELF header.
 */
void print_elf_data(Elf32_Ehdr *h)
{
printf("  Data:   ");
if (h->e_ident[EI_DATA] == ELFDATANONE)
printf("none\n");
else if (h->e_ident[EI_DATA] == ELFDATA2LSB)
printf("2's complement, little endian\n");
else if (h->e_ident[EI_DATA] == ELFDATA2MSB)
printf("2's complement, big endian\n");
else
printf("<unknown: %x>\n", h->e_ident[EI_DATA]);
}

/**
 * print_elf_version - prints the ELF file version from the ELF header.
 * @h: a pointer to the ELF header.
 */
void print_elf_version(Elf32_Ehdr *h)
{
printf("  Version:   %d\n", h->e_ident[EI_VERSION]);
}

/**
 * print_elf_osabi - prints the OS/ABI from the ELF header.
 * @h: a pointer to the ELF header.
 */
void print_elf_osabi(Elf32_Ehdr *h)
{
printf("  OS/ABI:     ");
switch (h->e_ident[EI_OSABI])
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
printf("Solaris ABI\n");
break;
case ELFOSABI_IRIX:
printf("IRIX ABI\n");
break;
case ELFOSABI_FREEBSD:
printf("FreeBSD ABI\n");
break;
case ELFOSABI_TRU64:
printf("TRU64 UNIX ABI\n");
break;
case ELFOSABI_ARM:
printf("ARM architecture ABI\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone (embedded) ABI\n");
break;
default:
printf("<unknown: %d>\n", h->e_ident[EI_OSABI]);
break;
}
}

/**
 * print_elf_abi_version - prints the ABI version from the ELF header.
 * @h: a pointer to the ELF header.
 */
void print_elf_abi_version(Elf32_Ehdr *h)
{
printf("ABI Version:  %d\n", h->e_ident[EI_ABIVERSION]);
}

/**
 * print_elf_type - prints the type from the ELF header.
 * @h: a pointer to the ELF header.
 */
void print_elf_type(Elf32_Ehdr *h)
{
printf("Type:  ");
switch (h->e_type)
{
case ET_NONE:
printf("NONE (Unknown type)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown: %x>\n", h->e_type);
break;
}
}

/**
 * print_elf_entry - prints the entry point from the ELF header.
 * @h: a pointer to the ELF header.
 */
void print_elf_entry(Elf32_Ehdr *h)
{
printf("Entry point address:    0x%x\n", h->e_entry);
}

/**
 * print_elf_header - prints the ELF header data.
 * @h: a pointer to the ELF header.
 */
void print_elf_header(Elf32_Ehdr *h)
{
printf("ELF Header:\n");
print_elf_magic(h);
print_elf_class(h);
print_elf_data(h);
print_elf_version(h);
print_elf_osabi(h);
print_elf_abi_version(h);
print_elf_type(h);
print_elf_entry(h);
}

/**
 * main - prints information about an ELF executable file.
 * @argc: the number of arguments.
 * @argv: the argument vector.
 *
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char **argv)
{
int fd;
struct stat st;
Elf32_Ehdr header;
if (argc != 2)
error_exit("Usage: elf_header elf_filename");
fd = open(argv[1], O_RDONLY);
if (fd == -1)
error_exit("Error: Can't open file");
fstat(fd, &st);
if (st.st_size < sizeof(Elf32_Ehdr))
error_exit("Error: Invalid ELF file");
if (read(fd, &header, sizeof(Elf32_Ehdr)) != sizeof(Elf32_Ehdr))
error_exit("Error: Failed to read header");
if (header.e_ident[EI_MAG0] != ELFMAG0 ||
header.e_ident[EI_MAG1] != ELFMAG1 ||
header.e_ident[EI_MAG2] != ELFMAG2 ||
header.e_ident[EI_MAG3] != ELFMAG3)
error_exit("Error: Not an ELF file");
print_elf_header(&header);
if (close(fd) == -1)
error_exit("Error: Can't close file");
return (0);
}
