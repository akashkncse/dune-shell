#ifndef SHELLH
#define SHELLH
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#define DSH_RL_BUFSIZE 1024
#define DSH_TOK_BUFSIZE 64
#define DELIM " \n\t\r\a"
char **dsh_split_line(char *);
char *dsh_read_line();
void dsh_loop();
int dsh_cd(char **);
int dsh_exit(char **);
int dsh_help(char **);
int dsh_num_builtin();
extern char *builtin_str[];
extern int (*builtin_func[])(char **);
#endif