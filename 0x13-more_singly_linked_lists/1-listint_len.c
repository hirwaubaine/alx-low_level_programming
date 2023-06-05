#include <stdio.h>
#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked listint_t list
 * @h: head of linked list
 * Return: number of elements in a linked list
 */
size_t listint_len(const listint_t *h)
{
	size_t nber = 0;

	while (h)
	{
		nber++;
		h = h->next;
	}
	return (nber);
}
