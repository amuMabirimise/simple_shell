#include "main.h"

/**
 * process_command - Process the command and execute corresponding actions.
 * @argv: Array of strings where argv[0] is the command.
 *
 * Return: 0 on success, 1 if the command was unsuccessful.
 */
int process_command(char **argv)
{
	int num_arg = num_args(argv);

	if (str_cmp(argv[0], "cd") == 0)
	{
		if (num_arg >= 1)
		{
			cd(argv[1]);
			return (0);
		}
	}
	if (str_cmp(argv[0], "env") == 0)
	{
		env_cust();
		return (0);
	}
	if (str_cmp(argv[0], "setenv") == 0)
	{
		if (num_arg == 3)
		{
			setenv_cust(argv[1], argv[2]);
			return (0);
		}
	}
	if (str_cmp(argv[0], "unsetenv") == 0)
	{
		if (num_arg == 2)
		{
			unsetenv_cust(argv[1]);
			return (0);
		}
	}
	return (1);
}

/**
 * print_errore - address exit error for string or negatives
 * @err: name of shell
 * @count: number of command
 * @c: name of command
 * @arg: argument of command
 */

void print_errore(char *err, int count, char *c, char *arg)
{
	print_cust(err);
	print_cust(": ");
	print_number(count);
	print_cust(": ");
	print_cust(c);
	print_cust(": Illegal number: ");
	print_cust(arg);
	print_cust("\n");
}
