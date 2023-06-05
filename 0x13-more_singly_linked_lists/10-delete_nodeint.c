#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index -  deletes the node at index of a linked list
 * @head: pointer to the very first node of the list
 * @index: index of the node that should be deleted
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *curr, *temp = *head;
	unsigned int n;

	if (temp == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}
	for (n = 0; n < (index - 1); n++)
	{
		if (temp->next == NULL)
			return (-1);
		temp = temp->next;
	}
	curr = temp->next;
	temp->next = curr->next;
	free(curr);
	return (1);
}
