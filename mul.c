#include "lists.h"

/**
 *p_mul - multiplie the top two elements of the stack
 *@head: double pointer to stack head
 *@line_counter: line number
 *Return: none (void)
 */

void p_mul(stack_t **head, unsigned int line_counter)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_counter);
		fclose(trans.monty_file);
		free(trans.line_content);
		p_free_stack(*head);
		exit(EXIT_FAILURE);
	}

	int result = (*head)->n * (*head)->next->n;
	stack_t *temp = *head;
	(*head)->next->n = result;
	*head = (*head)->next;
	free(temp);
}
