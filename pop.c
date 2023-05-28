#include "monty.h"

/**
 *p_pop - removes the top element of the stack
 *@head: double pointer to head of the stack
 *@line_counter: number of lines
 *Return: none (void)
 */

void p_pop(stack_t **head, unsigned int line_counter)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_counter);
		fclose(trans.monty_file);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	*head = (*head)->next;

	if (*head != NULL)
	{
		(*head)->prev = NULL;
	}
	free(temp);
}
