#include "monty.h"

/**
 * is_alphabetical - checks if int is in alphabet
 * @c: int
 * Return: 1 if yes, 0 if no
 */

int is_alphabetical(int c)
{
	return ((c >= 97 && c <= 122) || (c >= 65 && c <= 90));
}

/**
 * print_string - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void print_string(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *runner = *stack;

	while (runner && runner->n != 0 && is_alphabetical(runner->n))
	{
	putchar(runner->n);
	runner = runner->next;
	}
	putchar('\n');
}

