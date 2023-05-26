#include "monty.h"

/**
 *p_queue - sets trans.flag_change to 1 (queue)
 *__attribute__ - suppresses unused parameter warnings
 *@head: double pointer to the head of the stack
 *@line_count: line_number
 *Return: none (void)
 */

void p_queue(stack_t __attribute__((unused)) **head,
unsigned int __attribute__((unused)) line_count)
{
	trans.flag_change = 1;
}
