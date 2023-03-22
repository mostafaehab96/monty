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

