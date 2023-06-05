#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - deletes the head node of a linked list
 * @head: pointer to the very first node of the list
 * Return: the head node’s data (n)
 * or 0 if the linked list is empty
 */

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (*head == NULL)
		return (0);

	temp = *head;
	*head = temp->next;
	n = temp->n;
	free(temp);
	return (n);
}
