#include "lists.h"

/**
 *p_stack - sets trans.flag_change to 0 (stack)
 *__attribute__ - suppresses unused parameter warnings
 *@head: double pointer to teh head of the stack
 *@line_count: line_number
 *Return: none (void)
 */

void p_stack(stack_t __attribute__((unused)) **head,
unsigned int __attribute__((unused)) line_count)
{
	trans.flag_change = 0;
}
