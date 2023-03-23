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


/**
 * rotr - make the last element be the first
 * @stack: a pointer to the stack
 * @line: the line number of the operation
 */
void rotr(stack_t **stack, unsigned int line __attribute__((unused)))
{
	stack_t *t;
	int n;

	if (stack == NULL || *stack == NULL)
		return;

	t = *stack;
	if (!t->next)
		return;

	while (t->next)
		t = t->next;
	n = t->n;
	(t->prev)->next = NULL;
	free(t);

	push(stack, n);
}
