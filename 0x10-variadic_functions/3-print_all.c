#include "variadic_function.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 * c: char
 * i: integer
 * f: float
 * s: char* (if string is NULL, print (nil) instead
 * any other char should be ignored
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0, j;
	char *separator = "";
	print_fun types[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{'\0', NULL}
	};

	va_start(args, format);
	while (format && format[i])
	{
		j = 0;
		while (types[j].type)
		{
			if (types[j].type == format[i])
			{
				printf("%s", separator);
				types[j].func(args);
				separator = ", ";
				break;
			}
			j++;
		}
		i++;
	}
	va_end(args);

	printf("\n");
}

/**
 * print_char - prints char
 * @args: va_list that contains the char to print
 */
void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_int - prints integer
 * @args: va_list that contains the integer to print
 */
void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - prints float
 * @args: va_list that contains the float to print
 */
void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_string - prints string
 * @args: va_list that contains the string to print
 */
void print_string(va_list args)
{
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		printf("(nil)");
		return;
	}
	printf("%s", str);
}
