#include "monty.h"
/**
 * push - pushes an element onto the stack
 * @stack: stack
 * @line_number: element to add to the stack
 * Return: no return value
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *newnode;

	n = flag.n;
	if (flag.err_flag)
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
	else
	{
		newnode = malloc(sizeof(stack_t));
		if (newnode == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free(newnode);
			exit(EXIT_FAILURE);
		}

		newnode->n = n;
		newnode->prev = NULL;
		newnode->next = NULL;
		if (*stack == NULL)
			*stack = newnode;
		else
		{
			newnode->next = *stack;
			(*stack)->prev = newnode;
			*stack = newnode;
		}
	}
}
/**
 * pall - prints elements on the stack
 * @stack:the stack
 * @line_number: The line number
 * Return:no return value
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%i\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint - prints the top value on stack followed by a new line
 * @stack:the stack
 * @line_number:line number
 * Return:no return value
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		flag.err_flag = 1;
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
	}
	else
		printf("%i\n", (*stack)->n);
}
