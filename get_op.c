#include "monty.h"

/**
 * get_op - gets the right function to use from opcode
 * @s: the opcode
 * Return: a function pointer to the right function
 */
void (*get_op(char *s)) (stack_t **stack, unsigned int line)
{
	instruction_t codes[] = {
		{"push", push},
		{"pop", pop},
		{"pint", pint},
		{"pall", pall},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_f},
		{NULL, NULL}
	};
	int i;

	for (i = 0; codes[i].opcode != NULL; i++)
	{
		if (strcmp(codes[i].opcode, s) == 0)
			return (codes[i].f);
	}

	return (NULL);
}
