#include "main.h"

/**
 * read_file - reads a bytecode file and runs commands
 * @filename: pathname to file
 * @stack: pointer to the top of the stack
 */
void read_file(char *filename, stack_t **stack)
{
	char *line;
	size_t len = 0;
	int line_number = 1;
	instruction_func instruction;
	(void) len;

	var_global.file = fopen(filename, "r");
	if (var_global.file == NULL)
	{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
	}

	while (fgets(var_global.buffer,
				sizeof(var_global.buffer), var_global.file) != NULL)
	{
	line = var_global.buffer;
	line[strcspn(line, "\n")] = '\0';
	line = parse_line(var_global.buffer, stack, line_number);
	if (line == NULL || line[0] == '#')
	{
	line_number++;
	continue;
	}
	instruction = get_opcode_function(line);
	if (instruction == NULL)
	{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
	exit(EXIT_FAILURE);
	}
	instruction(stack, line_number);
	line_number++;
	}

	free(line);
	free(var_global.buffer);
	fclose(var_global.file);
}

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

