#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list
 * @h: a pointer to the list_t list
 * Return: the number of nodes
 */
size_t print_list(const list_t *h)
{
	while (h)
	{
		if (h->str == NULL)
			printf("[%u] %s%s", 0, "(nil)", "\n");
		else
			printf("[%u] %s%s", h->len, h->str, "\n");
		if (h->next)
		{
			return (1 + print_list(h->next));
	}
	return (1);
	}
	return (0);
}

