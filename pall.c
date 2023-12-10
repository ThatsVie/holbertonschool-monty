#include "monty.h"
/**
 * pall - prints all elements of the stack
 * @stack: pointer to the stack (linked list)
 * @line_number : line number in the Monty bytecode file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	while (*stack)
	{
		printf("%i\n", (*stack)->n);
		stack = &(*stack)->next;
	}
}
