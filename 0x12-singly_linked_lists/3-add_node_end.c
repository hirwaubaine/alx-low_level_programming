#include <stdio.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list
 * @head:@head: a head pointer of the list
 * @str: a string to add on the list
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	int len;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	for (len = 0; str[len];)
		len++;
	new->strdup(str);
	new->len = len;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	return (new);
}
while (temp->next)
	temp = temp->next;
	temp->next = new;
return (new);
}
