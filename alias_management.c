#include "main.h"

/**
 * init_standard_aliases - Init standard aliases
 * @aliases: a first element of the linked list of aliases
 */
void init_standard_aliases(alias_t **aliases)
{
	set_new_alias(aliases, "l", "ls -CF");
	set_new_alias(aliases, "la", "ls -A");
	set_new_alias(aliases, "ll", "ls -alF");
	set_new_alias(aliases, "ls", "ls --color=auto");
}

/**
 * alias_cmd_exec - alias command
 * @argv: argument
 * @num_arg: number of arguments
 *
 * Return: 0 if successful
 */
int alias_cmd_exec(char *argv[MAX_ARGS], int num_arg __attribute__((unused)))
{
	static alias_t *aliases;
	static int initialized;
	int i;
	char *name, *value;
	alias_t *alias;

	if (!initialized)
	{
		init_standard_aliases(&aliases);
		initialized = 1;
	}

	if (str_cmp(argv[0], "alias") != 0)
		return (0);

	if (num_arg == 1)
	{
		for (alias = aliases; alias; alias = alias->next)
			print_alias(alias);
		return (1);
	}
	for (i = 1; i < num_arg; i++)
	{
		name = argv[i];
		value = str_chr(argv[i], '=');
		if (value)
		{
			*value = '\0';
			value++;
			if (*value == '\0')
				continue;
			set_new_alias(&aliases, name, value);
		}
		else
		{
			print_all_aliases(aliases);
		}
	}
	return (1);
}


/**
 * set_new_alias - Adds a new alias to the linked list of aliases
 * @aliases: a first element of the linked list of aliases
 * @name: alias name
 * @value: alias value
 */
void set_new_alias(alias_t **aliases, char *name, char *value)
{
	alias_t *al;

	for (al = *aliases; al; al = al->next)
		if (str_cmp(al->name, name) == 0)
			break;

	if (al)
	{
		free(al->value);
		al->value = str_dup(value);
	}
	else
	{
		al = malloc(sizeof(*al));
		if (!al)
			return;
		al->name = str_dup(name);
		al->value = str_dup(value);
		al->next = *aliases;
		*aliases = al;
	}
	free(al);
}

/**
 * print_alias - prints an alias
 * @alias: the alias to print
 */
void print_alias(alias_t *alias)
{
	if (alias->value[0] != '\'')
	{
		write(1, "alias ", 6);
		write(1, alias->name, str_len(alias->name));
		write(1, "='", 2);
		write(1, alias->value, str_len(alias->value));
		write(1, "'\n", 2);
	}
	else
	{
		write(1, "alias ", 6);
		write(1, alias->name, str_len(alias->name));
		write(1, "=", 1);
		write(1, alias->value, str_len(alias->value));
		write(1, "\n", 1);
	}
}
