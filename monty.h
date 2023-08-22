#ifndef MONTY_H
#define MONTY_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/* Default Struct Definitions */
typedef struct stack_node_s
{
	int data;
	struct stack_node_s *prev;
	struct stack_node_s *next;
} stack_node_t;


typedef struct instruction_s
{
	char *opcode;
	instruction_func function;
} instruction_t;


#endif
