#include "monty.h"

/**
 * rotl- make the first element be the last
 * @stack: a pointer to the stack
 * @line: the line number of the operation
 */
void rotl(stack_t **stack, unsigned int line __attribute__((unused)))
{
	stack_t *t;
	stack_t *first;

	if (stack == NULL || *stack == NULL)
		return;

	t = *stack;

	if (!t->next)
		return;

	first = malloc(sizeof(stack_t));
	first->n = t->n;
	first->next = NULL;

	while (t->next)
		t = t->next;
	first->prev = t;
	t->next = first;
	pop(stack, 0);
}


