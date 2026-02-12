#include "shell.h"

int dsh_launch(char **args)
{
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            perror("dsh");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid == -1)
    {
        perror("dsh");
    }
    else
    {
        do
        {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}
int dsh_execute(char **args)
{
    int i;
    if (args[0] == NULL)
    {
        return 1;
    }
    return dsh_launch(args);
}
void dsh_loop()
{
    char *line;
    char **args;
    int status;

    do
    {
        printf(">> ");
        fflush(stdout);
        line = dsh_read_line();
        args = dsh_split_line(line);
        status = dsh_execute(args);
        free(line);
        free(args);
    } while (status);
}