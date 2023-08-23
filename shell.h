#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <errno.h>
#include <unistd.h>

#define MAX 25
#define MAX_ARGS 10

extern char **environ;

void execute_command(char *cmd, char *argv[]);
int stat_check(char *argv[]);
int cmd_check(char *cmd, int *i, char *argv[]);
int display_pmt(void);
int cmd_check(char *cmd, int *i, char *argv[]);
int _strcmp(char *s1, char *s2);
char *_getenv(char *path_name);
int _getline(char **buff);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

char *_strdup(char *str);

char *str_concat_(char *s1, char *s, char *s2);
ssize_t _read(int fd, void *buf, size_t count);
int get_path(char *argv, char **comand);
int _exitcmd(char *argv[]);
int stat_check_cat(char *ptr);

int put_e(char c);
int _perror(const char *str, ...);
int putnum(int x);

char *_strtok(char *str, const char *delim);

char *_strchr(const char *str, int character);
int _cd(char **args);

#endif
