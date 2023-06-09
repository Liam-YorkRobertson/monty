#include "monty.h"

/**
 *p_mul - multiply the top two elements of the stack
 *@head: double pointer to stack head
 *@line_counter: line number
 *Return: none (void)
 */

void p_mul(stack_t **head, unsigned int line_counter)
{
	int result;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_counter);
		fclose(trans.monty_file);
		exit(EXIT_FAILURE);
	}

	result = (*head)->n * (*head)->next->n;
	(*head)->next->n = result;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}
