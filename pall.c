#include "monty.h"

/**
 *p_pall - prints all items in stack
 *@head: double pointer to head of stack
 *@line_count: not used
 *Return: none (void)
 */

void p_pall(stack_t **head, unsigned int line_count)
{
	stack_t *current;
	(void) line_count;

	current = *head;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
