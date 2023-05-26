#include "lists.h"

/**
 *p_pall - prints all items in stack
 *@head: double pointer to head of stack
 *@counter: not used
 *Return: none (void)
 */

void p_pall(stack_t **head, unsigned int line_count)
{
	stack_t *current = *head;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
