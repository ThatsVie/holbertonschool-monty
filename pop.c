#include "monty.h"
/**
 * pop - removes the top element of the stack
 * @stack: pointer to pointer to top of stack
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *removed_element = NULL;/*to store the popped stack element.*/

	/*Check if the stack pointer or the stack itself is empty.*/
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	removed_element = *stack;/*Assign address of top node to temp pointer.*/
	*stack = (*stack)->next;/*Move stack point to next,removing top node.*/
	free(removed_element);/*Free the memory of removed node.*/
}
