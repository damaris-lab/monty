#include "monty.h"

/**
 * execute - executess the opcode
 * @input: The opcode function specified by the user
 * @stack: The stack
 * @line_number: The line number in the file
 * Return: 1 in case of error, Otherwise return 0
 */
void execute(char *input, stack_t **stack, int line_number)
{
	void (*func)(stack_t **, unsigned int);
	int i, j;
	int ref, result;
	char operation[40], op2[30];

	flag.err_flag = 0;
	result = sscanf(input, "%s%i%s%i", operation, &i, op2, &j);
	flag.err_flag = (result == -1 || operation[0] == '#') ? -1 : 0;
	if (flag.err_flag == -1)
		return;
	flag.n = i;
	ref = strcmp("push", operation);
	flag.err_flag = (ref == 0 && result != 2) ? 1 : 0;
	func = choose(operation);
	if (func == NULL)
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", line_number, operation);
		flag.err_flag = 1;
		return;
	}
	func(stack, line_number);
}
/**
 * stack_free - frees the stack
 * @stack: The stack
 * Return:no return value
 */
void stack_free(stack_t *stack)
{
	stack_t *ptr;

	while (stack != NULL)
	{
		ptr = stack->next;
		free(stack);
		stack = ptr;
	}
}

/**
 * choose - picks the fuction to execute
 * @operation: The function to look for
 * Return: A pointer to the function to execute
 */
void(*choose(char *operation))(stack_t **, unsigned int)
{
	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_func},
		{"mul", mul_func},
		{"mod", mod_func},
		{"pchar", pchar},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (functions[i].opcode != NULL)
	{
		if ((strcmp(functions[i].opcode, operation) == 0))
			break;
		i++;
	}
	return (functions[i].f);
}
