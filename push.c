#include "monty.h"
/**
 * push - pushes a new element onto the top of the stack
 * @stack: pointer to pointer to top of stack
 * @line_number: line number of read line
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value;/*stores integer value to be pushed onto the stack*/
	stack_t *new_element;/*pointer to new node to be added to stack.*/
	char *input_token;/*pointer to a string token.*/

	if (stack == NULL)/*Check if the double pointer to the stack is NULL*/
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*Tokenize input line using space, tab, and newline as delimiters.*/
	input_token = strtok(NULL, " \t\n");
	if (input_token == NULL)/*if no integer value provided*/
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(input_token);/*Convert tokenized string to integer*/
	
	/*Check if the token contains only digits, '+' or '-' characters.*/
	if (strspn(input_token, "0123456789+-") != strlen(input_token))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_element = malloc(sizeof(stack_t));/*Allocate memory*/

	if (new_element == NULL)/*Check if malloc failed to allocate memory.*/
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_element->n = value;/*set interger value of new node*/
	new_element->prev = NULL;/*Set previous pointer of new node to NULL.*/
	new_element->next = *stack;/*next pointer of new to current top stack*/

	if (*stack != NULL)
	{
		/*If not empty,update prev pointer to point to the new node */
		(*stack)->prev = new_element;
	}

	/*Update stack pointer to point to new node,now is new top of stack.*/
	*stack = new_element;
}


