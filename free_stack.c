#include "lists.h"

/**
 *p_free_stack - frees a doubly linked list
 *@head: double pointer to head of stack
 *Return: none (void)
 */

void p_free_stack(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free temp;
	}
}
