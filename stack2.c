#include "monty.h"

/**
 * validate - checks that the stack has minimum two elements
 * @stack: a pointer to the stack
 * @opcode: the operation code
 * @line: the line number of the operation
 * Return: 1 if has two or more elements 0 otherwise
 */
void validate(stack_t **stack, char *opcode, int line)
{
	if (stack && *stack)
	{
		if ((*stack)->next)
			return;
	}
	fprintf(stderr, "L%i: can't %s, stack too short\n", line, opcode);
	exit(EXIT_FAILURE);

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

	validate(stack, "swap", line);
	tmp = p->n;
	p->n = (p->next)->n;
	(p->next)->n = tmp;
}

/**
 * add - adds the top 2 elements in the stack in one element
 * @stack: a pointer to the stack
 * @line: line number of the operation
 */
void add(stack_t **stack, unsigned int line)
{
	int sum = 0;
	stack_t *p = *stack;

	validate(stack, "add", line);
	sum += p->n + (p->next)->n;
	(p->next)->n = sum;
	pop(stack, 0);
}

/**
 * nop - doesn't do anything
 * @stack: a pointer to the stack
 * @line: line number of operation
 */
void nop(stack_t **stack __attribute__((unused)),
		unsigned int line __attribute__((unused))) {}

/**
 * sub - substracte the top element from the second to element
 * @stack: a pointer to the stack
 * @line: the line number of the operation
 */
void sub(stack_t **stack, unsigned int line)
{
	int top;
	stack_t *p = *stack;

	validate(stack, "sub", line);
	top = p->n;
	p = p->next;
	p->n = (p->n) - top;
	pop(stack, 0);
}

