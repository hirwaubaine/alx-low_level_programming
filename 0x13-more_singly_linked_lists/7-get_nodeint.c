#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a linked list
 * @head: pointer to the very first node of the list
 * @index: index of the node
 * Return: pointer of the pointed node
 * or NULL, if the node does not exist
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	size_t n = 0;

	while (head && n < index)
	{
		head = head->next;
		n++;
	}
	return (head ? head : NULL);
}
