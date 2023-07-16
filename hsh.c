#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

void prompt_user(void)
{
    char command[MAX_COMMAND_LENGTH];
    char prompt[] = "$ ";

    while (1)
    {
        printf("%s", prompt);

        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            printf("\n");
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        if (strlen(command) > 0)
        {
            int status = system(command);
            if (status == -1)
            {
                printf("Error executing the command\n");
            }
        }
    }
}

int main(void)
{
    prompt_user();
    return (0);
}

