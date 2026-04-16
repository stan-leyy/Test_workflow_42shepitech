/*
** EPITECH PROJECT, 2026
** exec_coma.c
** File description:
** execute with coma
*/

#include "../include/my.h"

void condition(char **args, char **env)
{
    pid_t pid = fork();

    if (pid == 0)
        exec_child(args, env);
    else if (pid > 0)
        waitpid(pid, NULL, 0);
    else
        perror("fork");
}

void exec_coma(char *ori, char **env)
{
    char *line = my_strdup(ori);
    char *cmd = strtok(line, ";");
    char **args = NULL;
    char *copy = NULL;
    pid_t pid = 0;

    while (cmd) {
        copy = my_strdup(cmd);
        cmd = strtok(NULL, ";");
        args = parse(copy);
        condition(args, env);
        free(copy);
        free(args);
    }
    free(line);
}
