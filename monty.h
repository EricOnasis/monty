#ifndef MONTY_H
#define MONTY_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/* Default Struct Definitions */

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

/* Math Operation*/

void subtract(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void multiply(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void modulo(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
int is_alphabetical(int c);
void print_string(stack_t **stack, __attribute__((unused)) unsigned int line_number);

#endif
