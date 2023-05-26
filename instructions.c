#include "monty.h"

/**
 *instructions - runs the opcode
 *@line_content: line content
 *@stack: double pointer to head of stack
 *@line_counter: line counter
 *@monty_file: pointer to monty file
 *Return: none (void)
 */

int instructions(char *line_content, stack_t **stack, unsigned int line_counter, FILE *monty_file)
{
	instruction_t op_command[] = {
		{"push", p_push},
		{"pall", p_pall},
		{"pint", p_pint},
		{"pop", p_pop},
		{"swap", p_swap},
		{"add", p_add},
		{"nop", p_nop},
		{"sub", p_sub},
		{"div", p_div},
		{"mul", p_mul},
		{"queue", p_queue},
		{"stack", p_stack},
		{NULL, NULL}
	};

	char *op, *argu;

	op = strtok(line_content, " \n\t");
	if (op && op[0] == '#')
	{
		return (0);
	}

	argu = strtok(NULL, " \n\t");
	trans.argu = argu;

	for (int i = 0; op_command[i].opcode; i++)
	{
		if (strcmp(op, op[i].opcode) == 0)
		{
			op_command[i].f(stack, counter);
			return (0);
		}
	}

	if (op)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_counter, op);
		fclose(monty_file);
		free(line_content);
		p_free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
