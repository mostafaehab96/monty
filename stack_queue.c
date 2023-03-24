#include "monty.h"

/**
 * stack - converts the operation from queue is stack
 * @stack: a pointer to a stack
 * @line: line number of operation
 */
void stack(stack_t **stack __attribute__((unused)),
		unsigned int line __attribute__((unused)))
{
	is_stack = 1;
}

/**
 * queue - converts the operation from stack to queue
 * @stack: a pointer to stack
 * @line: line number of operation
 */
void queue(stack_t **stack __attribute__((unused)),
		unsigned int line __attribute__((unused)))
{
	is_stack = 0;
}

/**
 * push_q - pushed a new element to a queue
 * @stack: a pointer to the top of the stack
 * which will become the front of the queue
 * @n: the integer data to the new element
 */
void push_q(stack_t **stack, unsigned int n)
{
	stack_t *new, *p;

	new = malloc(sizeof(stack_t));

	if (stack == NULL || new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	p = *stack;
	new->n = n;
	if (p)
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
	else
		*stack = new;
	new->prev = p;
	new->next = NULL;

}
