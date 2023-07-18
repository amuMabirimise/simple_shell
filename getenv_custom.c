#include "main.h"

/**
 * get_env - getenv()
 * @str: string
 * Return: path
 */
char *get_env(char *str)
{
	int i = 0;
	int len = str_len(str);

	while (environ[i] != NULL)
	{
		if (strn_cmp(environ[i], str, len) == 0 && environ[i][len] == '=')
		{
			return (&(environ[i][len + 1]));
		}
		i++;
	}
	return (NULL);
}
