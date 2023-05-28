#include "monty.h"

/**
 *p_div - divides the top two elements of the stack
 *@head: double pointer to stack head
 *@line_counter: line number
 *Return: none (void)
 */

void p_div(stack_t **head, unsigned int line_counter)
{
	stack_t *temp;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_counter);
		fclose(trans.monty_file);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_counter);
		fclose(trans.monty_file);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n /= (*head)->n;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}
