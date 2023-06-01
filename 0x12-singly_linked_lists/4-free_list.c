#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees the linked list
 * @head: A pointer to the list
 */
void free_list(list_t *head)
{
	list_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head->str);
		free(head);
		head = tmp;
	}
}
