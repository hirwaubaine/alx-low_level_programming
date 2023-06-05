#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - adds a new node in a linked list,
 * at a given position
 * @head: pointer to the very first node of the list
 * @idx: index of the list where the new node should be added
 * @n: integer to be used for adding new node
 * Returns: the address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new, *temp = *head;
	unsigned int newnode;

	new = malloc(sizeof(listint_t));

	if (new == NULL)
	return (NULL);

	new->n = n;
	new->next = NULL;

	if (idx == 0)
	{
		new->next = temp;
		*head = new;
		return (new);
	}
	for (newnode = 0; newnode < (idx - 1); newnode++)
	{
		if (temp == NULL || temp->next == NULL)
			return (NULL);
		temp = temp->next;
	}
	new->next = temp->next;
	temp->next = new;

	return (new);
}
