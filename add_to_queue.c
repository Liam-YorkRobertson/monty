#include "lists.h"

/**
 *add_node_to_queue - Add new node to tail of the queue
 *@head: double pointer to head of queue
 *@n: new value
 *Return: none (void)
 */

void add_node_to_queue(stack_t **head, int n)
{
	stack_t *new_node, *current_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		return;
	}

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		current_node = *head;
		while (current_node->next)
		{
			current_node = current_node->next;
		}

		current_node->next = new_node;
		new_node->prev = current_node;
	}
}
