#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char *custom_getline()
{
	static char buffer[BUFFER_SIZE];
	static int position = 0;
	static int bytesRead = 0;

	while (1)
	{
	if (position >= bytesRead)
	{
		position = 0;
		bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (bytesRead <= 0)
		{
			return (NULL);
		}
	}

	while (position < bytesRead)
	{
		if (buffer[position] == '\n')
		{
			char *line = strdup(buffer);
			buffer[position] = '\0';
			position++;
			return (line);
		}
		position++;
	}
	}
}

char *replace_variables(char *command)
{
	char *ptr = command;
	char *start = NULL;
	char *end = NULL;

	while (*ptr != '\0')
	{
		if (*ptr == '$')
		{
		start = ptr + 1;
		end = start;

		while (*end != '\0' && (*end >= 'a' && *end <= 'z'))
		{
			end++;
		}

	if (end > start)
	{
		char variable[BUFFER_SIZE];
		strncpy(variable, start, end - start);
		variable[end - start] = '\0';

		if (strcmp(variable, "?") == 0)
		{
			int status = WEXITSTATUS(status);
			char exit_status[BUFFER_SIZE];
			size_t exit_len = strlen(exit_status);
			snprintf(exit_status, BUFFER_SIZE, "%d", status);
			
			memmove(ptr + exit_len, end, strlen(end) + 1);
			memcpy(ptr, exit_status, exit_len);

			ptr += exit_len;
			} else if (strcmp(variable, "$$") == 0)
			{

			pid_t pid = getpid();
			char process_id[BUFFER_SIZE];
			size_t pid_len = strlen(process_id);
			snprintf(process_id, BUFFER_SIZE, "%d", pid);
			
			memmove(ptr + pid_len, end, strlen(end) + 1);
			memcpy(ptr, process_id, pid_len);
		    
			ptr += pid_len;
		}
		}
	}

	ptr++;
	}

	return (command);
}

int main(void)
{
	char *command;

	while (1)
	{
	printf("$ ");

	command = custom_getline();
	if (command == NULL)
	{
		break;
	}

	command = replace_variables(command);

	if (strlen(command) > 0)
	{
		int status = system(command);
		if (status == -1)
		{
			printf("Error executing the command\n");
		}
	}
		free(command);
	}

	return (0);
}
