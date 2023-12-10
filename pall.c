#include "monty.h"
/**
 * pall - prints all elements of the stack
 * @stack: pointer to the stack (linked list)
 * @line_number : line number in the Monty bytecode file
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	/* Unused parameter, mentioned to avoid compiler warnings. */
	(void)line_number;

	/* Traverse the stack and print each element. */
	while (*stack)
	{
		printf("%i\n", (*stack)->n);
		stack = &(*stack)->next;
	}
}
