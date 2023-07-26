#include "main.h"

/**
* _exec - execute command
* @_argum: array of arguments
* @av: name of program
* @count: count of command
*/
void _exec(char **_argum, char *av, int count)
{
	char *cmd1;
	/*char *envp[] = {"TERM=xterm-256color", NULL};*/
	char err[50];
	int status;

	str_cpy(err, av);
	ex_code = 0;
	if (_argum[0][0] == '/')
	{
		if (access_file_check(_argum, NULL, err, count, environ))
			return;
	}
	else
	{
		if (_argum[0][0] != '.')
		{
			cmd1 = find_executable(_argum[0]);
			if (cmd1 == NULL)
			{
				print_error(err, count, _argum[0]);
				return;
			}
			if (access_file_check(_argum, cmd1, err, count, environ))
				return;
			free(cmd1);
		}
		else
		{
			cmd1 = _argum[0];
			if (access_file_check(_argum, cmd1, err, count, environ))
				return;
		}
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		ex_code = (WEXITSTATUS(status));
	}
}

/**
 * execve_cust - runs error code and exec
 * @c: command prompt
 * @p: arguments to command
 * @r: environment variable
 */

void execve_cust(char *c, char **p, char **r)
{
	if ((execve(c, p, r) == -1))
		ex_code = 127;
	ex_code = 1;
}

/**
 * print_error - printing error and checking exit code
 * @err: error string
 * @count: number of command
 * @c: name of file
 */

void print_error(char *err, int count, char *c)
{
	ex_code = 127;
	print_cust(err);
	print_cust(": ");
	print_number(count);
	print_cust(": ");
	print_cust(c);
	print_cust(": not found\n");
}

/**
 * print_cust - prints a character
 * @s: string input
 */

void print_cust(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		putchar_cust(s[i]);
		i++;
	}
}

/**
 * print_number - print number
 * @n: integer
 */

void print_number(int n)
{
	int first = n, count = 0, x = 1, i, tmp;

	tmp = n;

	if (n < 0)
	{
		putchar_cust('-');
		n = (n * -1) - 1;
	}
	while (first != 0)
	{
		first = first / 10;
		count++;
	}
	while (x <= count)
	{
		first = n;
		i = x;
		while (i < count)
		{
			first = first / 10;
			i++;
		}
		if (tmp < 0 && x == count)
			putchar_cust(((first % 10) + 48) + 1);
		else
			putchar_cust((first % 10) + 48);
		x++;
	}
	if (count == 0)
		putchar_cust('0');
}
