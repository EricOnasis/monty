#include "monty.h"



/**
 * main - main body for the monty program
 * @argc: int num of arguments
 * @argv: opcode file
 * Return: 0
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
	}

	read_file(argv[1], &stack);
	free_stack(stack);
	return (EXIT_SUCCESS);
}

/**
 * free_stack - free a list
 * @stack: pointer to first node
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
	tmp = stack;
	stack = stack->next;
	free(tmp);
	}
}

/**
 * get_op_func -	checks opcode and returns the correct function
 * @str: the opcode
 * Return: returns a functions, or NULL on failure
 */
instruction_func get_opcode_function(char *str)
{
	int i;

	instruction_t instructions[] = {
	{"push", push},
	{"pall", print_all},
	{"pint", print_int},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{"sub", subtract},
	{"mul", multiply},
	{"div", divide},
	{"mod", modulo},
	{"pchar", print_char},
	{"pstr", print_string},
	{"rotl", rotate_left},
	{"rotr", rotate_right},
	{NULL, NULL}
	};

	i = 0;
	while (instructions[i].f != NULL && strcmp(instructions[i].opcode, str) != 0)
	{
	i++;
	}

	return (instructions[i].f);
}

