#inlude "monty.h"
/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to pointer to top of stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node = *stack; /*initialize with the top node of the stack.*/
	int temp;

	/* Check if the stack is too short. */
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = top_node->n;/* Save the value of the top element. */
	top_node->n = top_node->next->n;/* Set value of top element to second element. */
	top_node->next->n = temp;/* Set value of second element to saved value. */
}
