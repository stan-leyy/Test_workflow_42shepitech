/*
** EPITECH PROJECT, 2026
** minishell.c
** File description:
** MINISHELL
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "../include/my.h"

void prompt(char **env)
{
    char buf[274];

    getcwd(buf, sizeof(buf));
    my_printf("\033[1m~>\033[1;33m%s\033[0m", buf);
    write(1, "$> ", 3);
}

int exec_and(char *stg, char **av, char ***env)
{
    char *line = my_strdup(stg);
    char **and_cmds = NULL;
    int i = 0;
    int ret = 0;

    if (dear_and(line)) {
        and_cmds = parse_and(line);
        while (and_cmds[i] != NULL) {
            av = parse(and_cmds[i]);
            expand_vars(av, *env);
            if (av && av[0]) {
                if (!handle_builtin(av, and_cmds[i], env))
                    ret = exec_cmd_ret(av, *env);
                else
                    ret = 0;
            }
            free(av);
            if (ret != 0)
                break;
            i++;
        }
        free(and_cmds);
        free(line);
        return 1;
    }
    free(line);
    return 0;
}

void control(char *stg, char **av, char ***env)
{
    char *line = my_strdup(stg);

    if (dear_and(line)) {
        exec_and(stg, av, env);
        free(line);
        return;
    }
    if (has_coma(line)) {
        exec_coma(line, *env);
        free(line);
    } else if (has_pipe(line)) {
        exec_pipe(line, *env);
        free(line);
    } else {
        av = parse(line);
        expand_vars(av, *env);
        if (av && av[0] && !handle_builtin(av, line, env))
            exec_cmd(av, *env);
        free(av);
        free(line);
    }
}

void shell_loop(char ***env)
{
    char *line = NULL;
    char **av = NULL;

    while (1) {
        prompt(*env);
        line = read_line();
        if (!line)
            break;
        control(line, av, env);
        free(line);
    }
}

int main(int ac, char **av, char **env)
{
    char **my_env;

    if (ac != 1)
        return 84;
    my_env = copy_env(env);
    if (!my_env)
        return 84;
    setup_signals();
    shell_loop(&my_env);
    free_env(my_env);
    return 0;
}