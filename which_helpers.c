#include "main.h"

/**
 * find_executable - find executable
 * @command: command
 * Return: path to executable
 */

char *find_executable(char *command)
{
	char *path = get_env("PATH");
	char *path_copy;
	char *dir;

	if (path == NULL)
	{
		return (NULL);
	}
	path_copy = str_dup(path);
	dir = str_tok(path_copy, ":");

	while (dir != NULL)
	{
		char full_path[1024];

		str_cpy(full_path, dir);
		str_cat(full_path, "/");
		str_cat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (str_dup(full_path));
		}
		dir = str_tok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

/**
 * print_all_aliases - prints aliases
 * @aliases: aliases
*/
void print_all_aliases(alias_t *aliases)
{
	alias_t *alias;

	for (alias = aliases; alias; alias = alias->next)
		print_alias(alias);
}
