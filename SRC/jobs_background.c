/*
** EPITECH PROJECT, 2026
** job_background.c
** File description:
** background execution
*/

#include "my.h"

int is_background(char **av)
{
    int i = 0;

    while (av[i] != NULL)
        i++;
    if (i > 0 && my_strcmp(av[i - 1], "&") == 0) {
        av[i - 1] = NULL;
        return 1;
    }
    return 0;
}

static void setup_child_bg(char *cmd, char **av, char **env)
{
    pid_t pid = getpid();

    setpgid(pid, pid);
    restore_signals();
    execve(dear_command(cmd, env), av, env);
    mini_printf("%s: Command not found.\n", cmd);
    exit(1);
}

void execute_background(principal_function_t *a,
    char **av, char **env)
{
    pid_t pid = fork();
    pid_t pgid = 0;

    if (pid == -1) {
        perror("fork");
        return;
    }
    if (pid == 0)
        setup_child_bg(av[0], av, env);
    pgid = pid;
    setpgid(pid, pgid);
    add_job(a, pid, pgid, av[0]);
}
