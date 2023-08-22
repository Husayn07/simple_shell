#include "shell.h"

/**
 * main - Entry point of the simple shell program
 *
 * Return: Always returns 0
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *token;
    char *args[2];
    int i = 0;

    while (1)
    {
        printf("$ ");

        read = getline(&line, &len, stdin);
        if (read == -1)
        {
            if (errno == 0)
                break;
            perror("getline");
            exit(EXIT_FAILURE);
        }

        if (line[read - 1] == '\n')
            line[read - 1] = '\0';

        token = strtok(line, " ");
        while (token != NULL)
        {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (strcmp(args[0], "exit") == 0)
            break;

        if (strcmp(args[0], "cd") == 0)
            _cd(args);
        else
            printf("Command not found: %s\n", args[0]);
    }

    free(line);
    return (0);
}
