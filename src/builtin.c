#include "shell.h"

char *builtin_str[] = {
    "cd",
    "help",
    "exit",
};

int (*builtin_func[])(char **) = {
    &dsh_cd,
    &dsh_help,
    &dsh_exit,
};

int dsh_num_builtin()
{
    return sizeof(builtin_str) / sizeof(char *);
}

int dsh_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "dsh: expected argument to \"cd\"\n");
    }
    else
    {
        if (chdir(args[1]) != 0)
        {
            perror("dsh");
        }
    }
    return 1;
}

int dsh_help(char **args)
{
    int i;
    printf("Akash's dune-shell\n");
    printf("The following functions are built in:-\n");
    for (i = 0; i < dsh_num_builtin(); i++)
    {
        printf("---\t%s\n", builtin_str[i]);
    }
    printf("Refer to man pages for information on other programs\n");
    return 1;
}

int dsh_exit(char **args)
{
    return 0;
}