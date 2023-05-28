#define  _GNU_SOURCE
#include "monty.h"

trans_t trans = {NULL, NULL, NULL, 0};

/**
 *check_arg_count - checks the number of passed to the program
 *@argc: argument count
 *Return: none (void)
 */

void check_arg_count(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 *init_monty_file - initializes a Monty file by opening it
 *@file_path: path to the monty file
 *Return: pointer to monty_file
 */

FILE *init_monty_file(char *file_path)
{
	FILE *monty_file = fopen(file_path, "r");

	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}
	return (monty_file);
}

/**
 *process_monty_file - reads each line of file, processes the line content
 *@monty_file: pointer to monty_file
 *@stack: pointer to stack
 *Return: none (void)
 */

void process_monty_file(FILE *monty_file, stack_t **stack)
{
	char *line_content = NULL;
	size_t buffer_size = 0;
	ssize_t line_read;
	unsigned int line_counter = 0;

	while ((line_read = getline(&line_content, &buffer_size, monty_file)) > 0)
	{
		trans.line_content = line_content;
		line_counter++;
		instruction(line_content, stack, line_counter, monty_file);
		line_content = NULL;
	}
}

/**
 *main - interprets monty code
 *@argc: argument count
 *@argv: argument vector
 *Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *monty_file;

	check_arg_count(argc);
	monty_file = init_monty_file(argv[1]);

	trans.monty_file = monty_file;

	process_monty_file(monty_file, &stack);

	fclose(monty_file);

	return (0);
}
