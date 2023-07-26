#include "main.h"

/**
 * print_llist - Print the contents of the linked list.
 * @head: The head of the linked list.
 */
void print_llist(struct Node *head)
{
	while (head != NULL)
	{
		write(STDOUT_FILENO, head->str, str_len(head->str));
		write(STDOUT_FILENO, "\n", 1);
		head = head->next;
	}
}

/**
 * free_llist - Free up memory allocated for each node in the linked list.
 * @head: The head of the linked list.
 */
void free_llist(struct Node *head)
{
	struct Node *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * env_cust - Print the environment variables.
 *
 * Return: Always 0.
 */
int env_cust(void)
{
	char **env;
	struct Node *head = NULL;

	for (env = environ; *env != NULL; env++)
	{
		add_node(&head, new_node(*env));
	}

	print_llist(head);

	free_llist(head);
	return (0);
}

/**
 * setenv_cust - Set an environment variable.
 * @name: The name of the environment variable.
 * @value: The value to be set.
 *
 * Return: Always 0.
 */
int setenv_cust(const char *name, const char *value)
{
	char **env;
	struct Node *head = NULL;
	/*extern char **environ;*/

	for (env = environ; *env != NULL; env++)
	{
		add_node(&head, new_node(*env));
	}

	add_new_env_var(&head, name, value);

	update_env(head);

	free_llist(head);
	return (0);
}

/**
 * unsetenv_cust - Delete an environment variable.
 * @name: The name of the environment variable to be deleted.
 *
 * Return: 0 on success, -1 on failure.
 */
int unsetenv_cust(const char *name)
{
	char **e;
	char **env;
	size_t len = str_len(name);

	for (env = environ; *env != NULL; env++)
	{
		if (strn_cmp(*env, name, len) == 0 && (*env)[len] == '=')
		{
			for (e = env; *e != NULL; e++)
			{
				*e = *(e + 1);
			}
			return (0);
		}
	}

	return (-1);
}
