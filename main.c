#include "monty.c"
/**
 * main - Monty Bytecode Interpreter
 * @argc: The count of command line arguments.
 * @argv: An array of strings representing the command line arguments.
 *
 * Return: EXIT_SUCCESS on successful execution, EXIT_FAILURE on failure.
 */
int main(int argc, char **argv)
{
	FILE *bytecode_file;/* File pointer to the Monty bytecode file. */
	char *current_line = NULL;/* Buffer to store line read from file. */
	char *opcode;/* Pointer to the current opcode extracted from a line. */
	size_t length = 0;/* Length of the line buffer. */
	ssize_t read;/* Number of characters read from a line. */
	unsigned int line_number = 1;/* Line number in the Monty bytecode file. */
	stack_t *stack_top = NULL;/* Pointer to the top of the stack. */

	/* Check if the correct number of command line arguments is provided. */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	/* Open the Monty bytecode file for reading. */
	bytecode_file = fopen(argv[1], "r");
	if (bytecode_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	/* Read lines from the Monty bytecode file. */
	read = getline(&current_line, &length, bytecode_file);
	while (read != -1)
	{
		/* Extract the opcode from the current line. */
		opcode = strtok(line, " \t\n");

		/* If opcode is NULL, line is empty; increment line number and continue. */
		if (opcode == NULL)
		{
			line_number = line_number + 1;
			read = getline(&current_line, &length, bytecode_file);
			continue;
		}

		 /* Execute the opcode by calling execute_opcode function. */
		execute_opcode(opcode, &stack, line_number);

		/* Read the next line and update the line number. */
		read = getline(&current_line, &length, bytecode_file);
		line_number = line_number + 1;
	}

	/* Free the allocated memory for the line buffer. */
	free(current_line);

	/* Free the entire stack. */
	free_stack(stack);

	/* Close the Monty bytecode file. */
	fclose(bytecode_file);

	/* Return EXIT_SUCCESS on successful execution. */
	return (EXIT_SUCCESS);
}
