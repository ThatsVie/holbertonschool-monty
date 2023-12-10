#include "monty.h"
/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @current_stack: Pointer to pointer to the stack in stack_t struct.
 * @line_number: Line number of the read opcode.
 */
void pint(stack_t **current_stack, unsigned int line_number)
{
	/*Check if the stack pointer or double pointer to the stack is NULL.*/
	if (*current_stack == NULL || current_stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	/*Print the integer value at the top of the stack.*/
	printf("%i\n", (*current_stack)->n);
}
