#include "function_pointers.h"
#include <stdio.h>
/**
 * print_n - print name using pointer to function
 * @n: string to add
 * @f: pointer to function
 * Return: nothing
 **/
void print_n(char *n, void (*f)(char *))
{
	if (n == NULL || f == NULL)
		return;

	f(n);
}
