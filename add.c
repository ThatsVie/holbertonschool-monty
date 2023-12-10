#include "monty.h"
/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to pointer to top of stack
 * @line_number: line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack or stack pointer is NULL. */
	if (stack == NULL || *stack == NULL)
	{
		/* Print an error message if the stack is empty. */
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);/* Exit the program with a failure status. */
	}

	/* Check if the stack is too short (less than two elements). */
	if ((*stack)->next == NULL)
	{
		/* Print an error message if the stack is too short. */
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE); /* Exit the program with a failure status. */
	}
	/* Add the top two elements of the stack. */
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	/* Remove the top element after addition. */
	pop(stack, line_number);
}
