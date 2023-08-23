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

