#include "monty.h"


/**
 * div_f - divides the second top element by the top element in the stack
 * @stack: a pointer to the stack
 * @line: the line number of the operation
 */
void div_f(stack_t **stack, unsigned int line)
{
	stack_t *p = *stack;
	int top;

	validate(stack, "div", line);

	top = p->n;
	if (top == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", line);
		exit(EXIT_FAILURE);
	}

	p = p->next;
	p->n = (p->n) / top;
	pop(stack, 0);
}

/**
 * mul - multiply the top two elements
 * @stack: a pointer to the stack
 * @line: the line number of the operation
 */
void mul(stack_t **stack, unsigned int line)
{
	stack_t *p = *stack;

	validate(stack, "mul", line);
	p = p->next;
	p->n = (p->n) * (p->prev)->n;
	pop(stack, 0);
}

/**
 * mod - computes the rest of the division of the second top element
 * by the top element of the stack
 * @stack: a pointer to the stack
 * @line: the line number to the operation
 */
void mod(stack_t **stack, unsigned int line)
{
	stack_t *p = *stack;
	int top;

	validate(stack, "mod", line);
	top = p->n;
	if (top == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	p = p->next;
	p->n = (p->n) % top;
	pop(stack, 0);
}
