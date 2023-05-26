#ifndef LISTS_H
#define LISTS_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct trans_s - transfers values through the program
 * @argu: value
 * @monty_file: pointer to the monty file
 * @line_content: content in the line
 * @flag_change: flag change (between stack and queue)
 *
 * Description: carries values through the program
 */

typedef struct trans_s
{
	char *argu;
	FILE *monty_file;
	char *line_content;
	int flag_change;
} trans_t;

extern trans_t trans;

void p_add(stack_t **head, unsigned int line_counter);
void add_node_to_queue(stack_t **head, int n);
void add_node_to_stack(stack_t **head, int n);
void p_div(stack_t **head, unsigned int line_counter);
void p_free_stack(stack_t *head);
void p_mul(stack_t **head, unsigned int line_counter);
void p_nop(stack_t **head, unsigned int line_counter);
void p_pall(stack_t **head, unsigned int line_count);
void p_pint(stack_t **head, unsigned int line_counter);
void p_pop(stack_t **head, unsigned int line_counter);
void p_push(stack_t **head, unsigned int line_count);
void p_queue(stack_t __attribute__((unused)) **head,
unsigned int __attribute__((unused)) line_count);
void p_stack(stack_t __attribute__((unused)) **head,
unsigned int __attribute__((unused)) line_count);
void p_sub(stack_t **head, unsigned int line_counter);
void p_swap(stack_t **head, unsigned int line_counter);
int instruction(char *line_content, stack_t **stack, unsigned int line_counter, FILE *monty_file);

#endif /*lists.h*/
