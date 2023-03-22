#include "monty.h"


/**
 * *_strdup -  a function that returns a pointer to
 * a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @s : pointer to the new str
 * Return: NULL or a pointer to the duplicated string
 */
char *_strdup(const char *s)
{
	int len;
	char *new;
	int i;

	if (s == NULL)
		return (NULL);

	len = strlen((char *) s);
	new = malloc(sizeof(char) * len + 1);

	if (new == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		new[i] = s[i];

	new[i] = '\0';

	return (new);
}

/**
 * tokenize - splits a string with a delimeter using strtok
 * getting only the first 3 words
 * @str: the string to be splitted
 * @delim: the delimeter
 * Return: an array of splitted words
 */

char **tokenize(char *str, const char *delim)
{
	char **words = NULL;
	int i = 0;
	char *copy = NULL, *token = NULL;

	if (str == NULL)
		return (NULL);

	words = (char **) malloc(sizeof(char *) * 3);
	if (words == NULL)
		return (NULL);

	copy = _strdup(str);
	token = strtok(copy, "\n"); /* removes new lines */
	token = strtok(token, "\t"); /* removes taps */
	token = strtok(token, delim);
	while (token != NULL)
	{
		words[i] = _strdup(token);
		i++;
		if (i == 2)
			break;
		token = strtok(NULL, delim);
	}
	words[i] = NULL;
	if (words[0])
	{
		if (words[0][0] == '#')
		{
			free(copy);
			free_arr(words);
			return (NULL);
		}
	}
	free(copy);
	return (words);
}

/**
 * run - a function that takes an array of opcodes and arguments
 * which should end with NULL and check the argumnet for push opcode
 * @ops: array of strings containing the line of monty
 * byte code space separated
 * @stack: a pointer to a stack to perform operations on it
 * @line_number: the line number in monty file
 */

void run(char **ops, stack_t **stack, unsigned int line_number)
{
	char *opcode, *arg;
	void (*op)(stack_t **stack, unsigned int line);
	int n, valid;

	if (ops == NULL)
		return;
	opcode = ops[0];
	if (opcode == NULL)
	{
		free_arr(ops);
		return;
	}
	arg = ops[1];
	if (strcmp(opcode, "push") == 0)
	{
		n = _atoi(arg, &valid);
		if (arg == NULL || !valid)
		{
			fprintf(stderr, "L%i: usage: push integer\n", line_number);
			free_arr(ops);
			exit(EXIT_FAILURE);
		}

		push(stack, n);
	}
	else
	{
		op = get_op(opcode);
		if (op == NULL)
		{
			fprintf(stderr, "L%i: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}

		op(stack, line_number);
	}
	free_arr(ops);

}

/**
 * _atoi - a function that converts a string to a number and checks
 * if it's valid (this is just of the "0" string which is valid
 * but the original atio will return 0 which is the same return for the invalid
 * @s: the string to be converted
 * @valid: a pointer to integer to work as a bool checking the validation
 * Return: the converted integer
 */
int _atoi(char *s, int *valid)
{
	int i;
	int n;

	if (s == NULL)
	{
		*valid = 0;
		return (0);
	}
	n = atoi(s);
	i = s[0] == '-' ? 1 : 0;
	for (; s[i] != '\0'; i++)
	{
		if (!isdigit(s[i]))
		{
			*valid = 0;
			return (0);
		}
	}

	*valid = 1;
	return (n);
}

/**
 * free_arr - frees an array of strings allocated in heap
 * @arr: the array to be freed
 */
void free_arr(char **arr)
{
	int i = 0;

	if (arr == NULL)
		return;

	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}

	free(arr);

}
