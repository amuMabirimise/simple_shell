#include "main.h"

/**
* getline_cust - Read The Input By User From Stdin
*
* Return: Input
*/
char *getline_cust(void)
{
	int i = 0;
	ssize_t nread;
	char c = 0, *buffer = malloc(sizeof(char) * BUFFER_SIZE);

	if (buffer == NULL)
	{
		return (NULL);
	}
	while (c != EOF && c != '\n')
	{
		nread = read(STDIN_FILENO, &c, 1);
		if (nread == 0 || nread == -1)
		{
			free(buffer);
			if (nread == 0)
				exit(ex_code);
			if (nread == -1)
				perror("Error: ");
		}
		buffer[i] = c;
		if (buffer[0] == '\n')
		{
			free(buffer);
			return ("\0");
		}
		if (i + 1 >= BUFFER_SIZE)
		{
			buffer = realloc_cust(buffer, i + 1);
			if (buffer == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}
		i++;
	}
	buffer[i - 1] = '\0';
	remwspaces(buffer);
	remove_comment_hash(buffer);
	return (buffer);
}

/**
* remove_comment_hash - Remove Comments From Input
* @buff: input buffer
*/
void remove_comment_hash(char *buff)
{
	int i = 0;

	while (buff[i] != '\0')
	{
		if (buff[i] == '#')
			buff[i] = '\0';
		i++;
	}
}
