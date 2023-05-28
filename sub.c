#include "monty.h"

/**
 *p_sub - subtracts the top two elements of the stack
 *@head: double pointer to stack head
 *@line_counter: line number
 *Return: none (void)
 */

void p_sub(stack_t **head, unsigned int line_counter)
{
	int diff;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_counter);
		fclose(trans.monty_file);
		exit(EXIT_FAILURE);
	}

	diff = (*head)->next->n - (*head)->n;
	(*head)->next->n = diff;
	*head = (*head)->next;
	(*head)->prev = NULL;
}
