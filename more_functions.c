#include "monty.h"

/**
 * pop - remove element a list
 *@stack: pointer to first node
 *@line_number: integer
 *Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack)
	(*stack)->prev = NULL;

	free(temp);
}

/**
 * swap - swap top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;
	stack_t *runner = *stack;

	if (!runner || !runner->next)
	{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	tmp = runner->n;
	runner->n = runner->next->n;
	runner->next->n = tmp;
}

/**
 * nop - nop top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void nop(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	/* No operation (Do nothing) */
}

/**
 * rotate_left - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void rotate_left(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *first = *stack, *last;

	if (!first || !first->next)
	return;

	last = first;
	while (last->next)
	last = last->next;

	last->next = first;
	first->prev = last;
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
}

/**
 * rotate_right - mod top of stack y second top stacks
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void rotate_right(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *last = *stack, *new_last;

	if (!last || !last->next)
	return;

	while (last->next)
	last = last->next;

	new_last = last->prev;
	new_last->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
}
