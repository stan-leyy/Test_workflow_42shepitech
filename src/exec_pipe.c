/*
** EPITECH PROJECT, 2026
** exec_pipe.c
** File description:
** execution of commands with pipe
*/

#include "../include/my.h"

void exec_stage(char *cmd, int in, int out, char **env)
{
    int pid = fork();
    char **av;

    if (pid == 0) {
        if (in != 0)
            dup2(in, 0);
        if (out != 1)
            dup2(out, 1);
        if (in != 0)
            close(in);
        if (out != 1)
            close(out);
        av = parse(cmd);
        exec_child(av, env);
        exit(0);
    }
}

void exec_pipe(char *line, char **env)
{
    char *copy = my_strdup(line);
    char **cmd = parse_pipe(copy);
    int fd[2];
    int i = 0;
    int in = 0;

    for (int i = 0; cmd[i] != NULL; i++) {
        if (cmd[i + 1])
            pipe(fd);
        else
            fd[1] = 1;
        exec_stage(cmd[i], in, fd[1], env);
        if (in != 0)
            close(in);
        if (cmd[i + 1]) {
            close(fd[1]);
            in = fd[0];
        }
    }
    while (wait(NULL) > 0);
    free(copy);
    free(cmd);
}
