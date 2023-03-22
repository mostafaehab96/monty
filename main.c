#include "monty.h"
#define BUFFERSIZE 1024

/**
 * main - entry point of the program
 * an interpeter for monty files
 * @argc: the arguments count
 * @argv: the arguments
 * Return: 0 Success
 */
int main(int argc, char *argv[])
{
	stack_t *top = NULL;
	FILE *fp;
	char buffer[BUFFERSIZE];
	char *file_name;
	char **ops;
	unsigned int line_number;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_name = argv[1];
	fp = fopen(file_name, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, BUFFERSIZE, fp) != NULL)
	{
		line_number++;
		ops = tokenize(buffer, " ");
		run(ops, &top, line_number);
	}

	fclose(fp);
	free_stack(top);


	return (0);
}
