#include "lists.h"

/**
 *main - interprets monty code
 *@argc: argument count
 *@argv: argument vector
 *Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	trans_t trans = {NULL, NULL, NULL, 0};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE monty file\n");
		exit(EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");

	trans.monty_file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	while ((read = getline(&line, &len, file)) != -1)
	{
		trans.line_content = line;
		line_number++;
		execute(line, &stack, line_number, file);
	}

	free(line);
	fclose(file);
	p_free_stack(stack);
	return (0);
}
