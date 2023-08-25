#include "monty.h"

void read_file(char *filename, stack_t **stack);
global_var_t var_global;

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
	(void)len;

	var_global.file = fopen(filename, "r");
	if (var_global.file == NULL)
	{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
	}

	while (fgets(var_global.buffer, sizeof(var_global.buffer),
				var_global.file) != NULL)
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

	fclose(var_global.file);
}
