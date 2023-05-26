#define  _GNU_SOURCE
#include <stdio.h>
#include "monty.h"

/**
 *main - interprets monty code
 *@argc: argument count
 *@argv: argument vector
 *Return: 0 (success)
 */

trans_t trans = {NULL, NULL, NULL, 0};

int main(int argc, char *argv[])
{
	FILE *m_file;
	char *line = NULL;
	size_t characters, len = 0;
	ssize_t read;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *line_content;
	
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	m_file = fopen(argv[1], "r");
	trans.monty_file = m_file;

	if (!m_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	characters = getline (&line, &len, m_file);
	while ((read = characters) != -1)
	{
		line_content = NULL;
		trans.line_content = line_content;
		line_number++;
		instruction(line_content, &stack, line_number, m_file);
	}

	free(line);
	fclose(m_file);
	p_free_stack(stack);
	return (EXIT_SUCCESS);
}
