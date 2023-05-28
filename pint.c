#include "monty.h"

/**
 *p_pint - prints the value at the top of the stack
 *@head: double pointer to head of stack
 *@line_counter: number of lines
 *Return: none (void)
 */

void p_pint(stack_t **head, unsigned int line_counter)
{
	if (*head)
	{
		printf("%d\n", (*head)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_counter);
		fclose(trans.monty_file);
		exit(EXIT_FAILURE);
	}
}
