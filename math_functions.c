#include "monty.h"

/**
 * subtract - sub top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void subtract(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *runner = *stack;

	if (!runner || !runner->next)
	{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	result = runner->next->n - runner->n;
	pop(stack, line_number);
	(*stack)->n = result;
}

/**
 * add - add top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void add(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *runner = *stack;

	if (!runner || !runner->next)
	{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	result = runner->next->n + runner->n;
	pop(stack, line_number);
	(*stack)->n = result;
}

/**
 * multiply - mul top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void multiply(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *runner = *stack;

	if (!runner || !runner->next)
	{
	fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	result = runner->next->n * runner->n;
	pop(stack, line_number);
	(*stack)->n = result;
}

/**
 * divide - div top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void divide(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *runner = *stack;

	if (!runner || !runner->next)
	{
	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	if (runner-> n == 0)
	{
	fprintf(stderr, "L%d: division by zero\n", line_number);
	exit(EXIT_FAILURE);
	}

	result = runner->next-> n / runner-> n;
	pop(stack, line_number);
	(*stack)-> n = result;
}

/**
 * modulo - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void modulo(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *runner = *stack;

	if (!runner || !runner->next)
	{
	fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	if (runner-> n == 0)
	{
	fprintf(stderr, "L%d: division by zero\n", line_number);
	exit(EXIT_FAILURE);
	}

	result = runner->next-> n % runner-> n;
	pop(stack, line_number);
	(*stack)-> n = result;
}
