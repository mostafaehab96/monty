#include "monty.h"

/**
 * push - pushes an element at the top of the stack
 * @stack: a pointer to the top of the stack
 * @n: the integer data of the element to be pushed
 */
void push(stack_t **stack, unsigned int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (stack == NULL || new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - prints the stack
 * @stack: a pointer to the stack
 * @line: the line number of the operation
 */
void pall(stack_t **stack, unsigned int line __attribute__((unused)))
{
	stack_t *p;

	if (stack == NULL)
		return;
	p = *stack;
	while (p)
	{
		printf("%i\n", p->n);
		p = p->next;
	}

}

/**
 * pop - deletes the top of the stack
 * @stack: a pointer to the stack
 * @line: the line number of operation
 */
void pop(stack_t **stack, unsigned int line)
{
	stack_t *p;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	p = *stack;

	*stack = p->next;
	free(p);
	if (*stack)
		(*stack)->prev = NULL;
}

/**
 * pint - prints the top element in the stack
 * @stack: a pointer to the stack
 * @line: the line number of the operation
 */
void pint(stack_t **stack, unsigned int line)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}

	printf("%i\n", (*stack)->n);
}
