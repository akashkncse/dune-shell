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
char **dsh_split_line(char *line);
char *dsh_read_line();
void dsh_loop();
#endif