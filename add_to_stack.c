#include "monty.h"

/**
 *add_node_to_stack - adds node to the stack
 *@head: double pointer to head of stack
 *@n: new value
 *Return: none (void)
 */

void add_node_to_stack(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}

	*head = new_node;
}
