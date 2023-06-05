#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - rees a listint_t list
 * @head: pointer to the very first node of the list
 */

void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
		return;

	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	head = NULL;
}
