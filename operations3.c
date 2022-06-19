#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element of the
 * stack by the top element of the stack.
 *
 * @stack: first node in the list
 * @nline: line  currently on
 */
void mod(stack_t **stack, unsigned int nline)
{
	stack_t *future;

	future = *stack;
	if (!future || !future->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", nline);
		free_monty();
		exit(EXIT_FAILURE);
	}

	if (future->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", nline);
		free_monty();
		exit(EXIT_FAILURE);
	}

	future->next->n %= future->n;	/* update value of next */
	future = future->next;
	future->prev = NULL;
	free(*stack);
	*stack = future;
}

/**
 * pchar - prints the char at the top of the stack
 *
 * @stack: first node in the list
 * @nline: line  currently on
 */
void pchar(stack_t **stack, unsigned int nline)
{
	if (!stack || !*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", nline);
		free_monty();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n", nline);
		free_monty();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 *
 * @stack: first node in the list
 * @nline: line  currently on
 */
void pstr(stack_t **stack, unsigned int nline)
{
	stack_t *current;
	(void) nline;

	current = *stack;

