#include "monty.h"

/**
 * valid_count - checks that the stack has minimum two elements
 * @stack: a pointer to the stack
 * Return: 1 if has two or more elements 0 otherwise
 */
int valid_count(stack_t **stack)
{
	if (stack && *stack)
	{
		if ((*stack)->next)
			return (1);
	}
	return (0);
}

/**
 * swap - swaps the top 2 element of the stack
 * @stack: a pointer to the top of the stack
 * @line: the line number of the operation
 */
void swap(stack_t **stack, unsigned int line)
{
	int tmp;
	stack_t *p = *stack;

	if (!valid_count(stack))
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	tmp = p->n;
	p->n = (p->next)->n;
	(p->next)->n = tmp;
}
