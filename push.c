#include <stdbool.h>
#include "monty.h"

/**
 *p_push - adds a node to the top of the stack (push opcode)
 *@head: double pointer to head of stack
 *@line_count: the line number
 *Return: none (void)
 */

void p_push(stack_t **head, unsigned int line_count)
{
	int a, b, flag;

	if (!trans.argu)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_count);
		fclose(trans.monty_file);
		exit(EXIT_FAILURE);
	}
	b = 0;
	if (trans.argu[0] == '-')
	{
		b++;
	}
	flag = 0;
	for (; trans.argu[b] != '\0'; b++)
	{
		if (flag)
		{
			if (trans.argu[b] < '0' || trans.argu[b] > '9')
			{
				flag = 1;
				fprintf(stderr, "L%d: usage:push integer\n", line_count);
				fclose(trans.monty_file);
				exit(EXIT_FAILURE);
			}
		}
	}
	a = atoi(trans.argu);
	if (trans.flag_change == 0)
	{
		add_node_to_stack(head, a);
	}
	else
	{
		add_node_to_queue(head, a);
	}
}
