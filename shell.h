#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


#define MAX 10

extern char **environ;
int stat_check(char *argv[], int argc);
int cmd_check(char *cmd, int *i, char *argv[]);
int display_pmt();
void execute_command(char *argv[], char *envp[]);
int _strcmp(char *s1, char *s2);


#endif
