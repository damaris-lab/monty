#include "monty.h"
/**
 * pop - removes the top element of the stack
 * @stack:stack
 * @line_number: The file line number
 * Return:no return value
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		flag.err_flag = 1;
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
	}
	else
	{
		temp = *stack;
		*stack = (*stack)->next;
		if ((*stack) != NULL)
			(*stack)->prev = NULL;
		free(temp);
	}
}

/**
 * swap - swaps the two top elements of the stack
 * @stack:stack
 * @line_number: The file line number
 *Return:no value
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		flag.err_flag = 1;
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
	}
	else
	{
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
}
/**
 * add - adds the two top elements of the stack
 * @stack:stack
 * @line_number: The file line number
 * Return:returns no value
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		flag.err_flag = 1;
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
	}
	else
	{
		(*stack)->next->n += (*stack)->n;
		pop(stack, line_number);
	}
}
