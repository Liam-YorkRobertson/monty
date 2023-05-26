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
	FILE *file;
	char *line;
	size_t len;
	ssize_t read;
	stack_t *stack;
	unsigned int line_number;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE monty file\n");
		exit(EXIT_FAILURE);
	}
       
	file = fopen(argv[1], "r");
	trans.monty_file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line = NULL;
	len = 0;
	stack = NULL;
	line_number = 0;

	while ((read = getline(&line, &len, file)) != -1)
	{
		trans.line_content = line;
		line_number++;
		instructions(line_content, &stack, line_counter, monty_file);
	}

	free(line);
	fclose(file);
	p_free_stack(stack);
	return (0);
}
