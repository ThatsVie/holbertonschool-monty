#include "monty.h"
/**
 * execute_opcode - connects opcode to corresponding function
 * @opcode: pointer to opcode to match
 * @stack: pointer to pointer to stack
 * @line_number: line number
 */
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
	};
	/* Loop through the array of instructions. */
	while (instructions[i].opcode != NULL)
	{
		/* Check if the opcode matches the current instruction. */
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			/* Call the corresponding function for the matched opcode. */
			instructions[i].f(stack, line_number);
			return;

		}
		i++;
	}
	/* Print an error message for an unknown opcode. */
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);/* Exit the program with a failure status. */

}
