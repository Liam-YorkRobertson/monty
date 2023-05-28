#include "monty.h"

/**
 *p_add - adds the top two elements of the stack
 *@head: double pointer to stack head
 *@line_counter: line number
 *Return: none (void)
 */

void p_add(stack_t **head, unsigned int line_counter)
{
	stack_t *temp = *head;
	int sum;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_counter);
		fclose(trans.monty_file);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	sum = temp->n + temp->next->n;
	temp->next->n = sum;
	*head = temp->next;
	free(temp);
}
