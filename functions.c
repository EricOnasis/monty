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

/**
 * print_char - prints the ASCII value of a number
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
	exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
	exit(EXIT_FAILURE);
	}

	putchar((*stack)->n);
	putchar('\n');
}

/**
 * is_number - checks if a string is a number
 * @str: string being passed
 * Return: returns 1 if string is a number, 0 otherwise
 */
int is_number(const char *str)
{
	int i = 0;

	if (str == NULL)
	return (0);

	if (str[0] == '-')
	i = 1;

	for (; str[i] != '\0'; i++)
	{
	if (!isdigit(str[i]))
	return (0);
	}
	return (1);
}

/**
 * parse_line - parses a line for an opcode and arguments
 * @line: the line to be parsed
 * @stack: pointer to the head of the stack
 * @line_number: the current line number
 * Return: returns the opcode or null on failure
*/
char *parse_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *op_code, *push, *arg;
	(void)**stack;

	push = "push";
	op_code = strtok(line, "\n ");
	if (op_code == NULL)
	return (NULL);

	if (strcmp(op_code, push) == 0)
	{
	arg = strtok(NULL, "\n ");
	if (arg != NULL && is_number(arg))
	{
	var_global.push_arg = atoi(arg);
	}
	else
	{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
	}
	}
	return (op_code);
}
