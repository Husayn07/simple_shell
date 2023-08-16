#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdarg.h>

#define MAX 25
char *comand;

extern char **environ;
int stat_check(char *argv[], int argc);
int cmd_check(char *cmd, int *i, char *argv[]);
int display_pmt();
void execute_command(char *cmd, char *argv[], char *envp[]);
int _strcmp(char *s1, char *s2);
char *_getenv(char *path_name); 
char *_strdup(char *str);
char *str_concat_(char *s1, char *s, char *s2);
ssize_t _read(int fd, void *buf, size_t count);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int get_path(char* argv);
int stat_check_cat(char *ptr);

int put_e(char c);
int  _perror(const char *str, ...);
int putnum(int x);



#endif
