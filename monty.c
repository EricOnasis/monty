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
