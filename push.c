#include "monty.h"

/**
 *p_push - adds a node to the top of the stack (push opcode)
 *@head: double pointer to head of stack
 *@line_count: the line number
 *Return: none (void)
 */

void p_push(stack_t **head, unsigned int line_count)
{
	int a, b = 0;
	bool is_neg = false;

	if (!trans.argu)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_count);
		fclose(trans.monty_file);
		free(trans.line_content);
		p_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (trans.argu[0] == "-")
	{
		is_neg = true;
		b++;
	}
	for (; trans.argu[b] != '\0'; b++)
	{
		if (trans.argu[b] < '0' || trans.argu[b] > '9')
		{

			fprintf(stderr, "L%d: usage:push integer\n", line_count);
			fclose(trans.monty_file);
			free(trans.line_content);
			p_free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	a = atoi(trans.argu);
	if (trans.flag_change == 0)
	{
		add_node_to_stack(head, n);
	}
	else
	{
		add_node_to_queue(head, n);
	}
}
