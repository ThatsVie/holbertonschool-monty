Monty Bytecode Interpreter
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (similar to Python). The language relies on a unique stack with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCode files.
Example
push 0
push 1
push 2
  push 3
pall
push 4
  push 5
    push 6
pall
Monty byte code files can contain blank lines (empty or spaces only), and any additional text after the opcode or its required argument is ignored.

Example:
push 0 Push 0 onto the stack
push 1 Push 1 onto the stack

push 2
  push 3
    pall

push 4

  push 5

    push 6

pall This is the end of our program. Monty is awesome!
Monty Program Usage
Usage: monty file
file: Path to the file containing Monty byte code.
If the user provides no file or more than one argument, the program prints the error message USAGE: monty file and exits with the status EXIT_FAILURE.

If the file cannot be opened, the program prints the error message Error: Can't open file <file> and exits with the status EXIT_FAILURE, where <file> is the name of the file.

If the file contains an invalid instruction, the program prints the error message L<line_number>: unknown instruction <opcode> and exits with the status EXIT_FAILURE, where <line_number> is the line number where the invalid instruction appears (starting from 1).

Monty Program Execution
The Monty program runs the bytecodes line by line and stops if:

It executes every line of the file without errors.
It finds an error in the file.
An error occurs.
If the program can't allocate more memory (malloc failure), it prints the error message Error: malloc failed and exits with the status EXIT_FAILURE. The program is only allowed to use malloc and free from the memory allocation functions.

Code Structure
monty.h
Header file containing struct definitions, function prototypes, and necessary library inclusions.

monty.c
Main interpreter logic, including the execute_opcode function to connect opcodes to corresponding functions.


Functions for stack operations such as push, pall, pint, pop, swap, add, and nop.


Functions for managing the stack, including free_stack to free the entire stack.

main.c
Entry point for the Monty Bytecode Interpreter. Parses command line arguments, reads bytecode file, and executes instructions.

How to Run
Compile the program using your preferred compiler:
gcc -Wall -Werror -Wextra -pedantic *.c -o monty

Run the interpreter:
./monty <file.m>
