#include "monty.h"
/**
 * free_stack - frees stack_t stack
 * @stack: stack to be freed
 */
void free_stack(stack_t *stack)
{
	stack_t *next_node;

	while (stack != NULL)
	{
		next_node = stack->next;/* Store next node before freeing current node. */
		free(stack);/* Free the current node. */
		stack = next_node;/* Move to the next node. */
	}
}
