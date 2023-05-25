#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_all - prints anything
 * @format: is a list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	int i = 0;
	char *str, *punct = "";

	va_list list;

	va_start(list, format);

	if (format)
	{
		while (format[i])
		{
			switch (format[i])
			{
				case 'c':
					printf("%s%c", punct, va_arg(list, int));
					break;
				case 'i':
					printf("%s%d", punct, va_arg(list, int));
					break;
				case 'f':
					printf("%s%f", punct, va_arg(list, double));
					break;
				case 's':
					str = va_arg(list, char *);
					if (!str)
						str = "(nil)";
					printf("%s%s", punct, str);
					break;
				default:
					i++;
					continue;
			}
			punct = ", ";
			i++;
		}
	}

	printf("\n");

	va_end(list);
}
