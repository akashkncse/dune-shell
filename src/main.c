#include "main.h"

char **dsh_split_line(char *line)
{
    int bufsize = DSH_TOK_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "dsh: allocation error!");
        return EXIT_FAILURE;
    }

    token = strtok(line, DELIM);
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= bufsize)
        {
            bufsize += DSH_TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize);
            if (!tokens)
            {
                fprintf(stderr, "dsh: allocation error!");
                return EXIT_FAILURE;
            }
        }
        token = strtok(NULL, DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

char *dsh_read_line()
{
    int buf_size = DSH_RL_BUFSIZE;
    char c;
    int position = 0;
    char *buffer = malloc(sizeof(char) * buf_size);

    if (!buffer)
    {
        fprintf(stderr, "dsh: allocation error!");
        return EXIT_FAILURE;
    }

    while (1)
    {
        c = getchar();

        if (c == EOF || c == '\n')
        {
            buffer[position] = '\0';
            return buffer;
        }
        else
        {
            buffer[position] = c;
        }
        position++;

        if (position > buf_size)
        {
            buf_size += DSH_RL_BUFSIZE;
            buffer = realloc(buffer, buf_size);
            if (!buffer)
            {
                fprintf(stderr, "dsh: allocation error!");
                return EXIT_FAILURE;
            }
        }
    }
}

void dsh_loop()
{
    char *line;
    char **args;
    int status;

    do
    {
        printf(">> ");
        line = dsh_read_line();
        args = dsh_split_line(line);
        status = dsh_execute(args);
        free(line);
        free(args);
    } while (status);
}

int main(int ac, char **av)
{
    dsh_loop();

    return EXIT_SUCCESS;
}