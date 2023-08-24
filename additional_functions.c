#include "monty.h"

/**
 * push - push int to a stack
 * @stack: linked lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	(void) line_number;

	if (!new_node)
	{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
	}

	new_node->n = var_global.push_arg;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack)
	(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * print_all - print all function
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void print_all(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *runner = *stack;

	while (runner)
	{
	printf("%d\n", runner->n);
	runner = runner->next;
	}
}

/**
 * print_int - print int a top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void print_int(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

