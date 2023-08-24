#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/* Struct Definitions */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_var_s - opcoode and its function
 * @file: the opcode
 * @push_arg: function to handle the opcode
 * @buffer: pointer
 */
typedef struct global_var_s
{
	FILE *file;
	int push_arg;
	char *buffer;
} global_var_t;


extern global_var_t var_global;

typedef void (*instruction_func)(stack_t **stack, unsigned int line_number);

/* Monty Function Declarations */
/*void read_file(char *filename, stack_t **stack);*/
instruction_func get_opcode_function(char *str);
void push(stack_t **stack, unsigned int line_number);
void print_all(stack_t **stack, unsigned int line_number);
void print_int(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void rotate_left(stack_t **stack, unsigned int line_number);
void rotate_right(stack_t **stack, unsigned int line_number);
void print_char(stack_t **stack, unsigned int line_number);
void print_string(stack_t **stack, unsigned int line_number);
void subtract(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void multiply(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void modulo(stack_t **stack, unsigned int line_number);
int is_alphabetical(int c);
void free_stack(stack_t *stack);
char *parse_line(char *line, stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
