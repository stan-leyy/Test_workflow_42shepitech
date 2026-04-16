/*
** EPITECH PROJECT, 2026
** exec_cmd.c
** File description:
** execute commands
*/

#include "../include/my.h"

void handle_signal(int status)
{
    int sig = 0;

    if (WIFSIGNALED(status)) {
        sig = WTERMSIG(status);
        write(2, strsignal(sig), my_strlen(strsignal(sig)));
        if (WCOREDUMP(status))
            write(2, " (core dumped)", 14);
        write(2, "\n", 1);
    }
}

void exec_child(char **args, char **env)
{
    struct stat st;
    char *cmd = NULL;
    redirect_t redi = {0, NULL};

    check_redirect(&redi, args);
    if (redi.type > 0) {
        delete_symbol_and_file(&redi, args);
        apply_redirect(&redi);
    }
    cmd = find_cmd(args[0], env);
    if (!cmd) {
        write(2, args[0], my_strlen(args[0]));
        write(2, ": Command not found.\n", 21);
        exit(1);
    }
    stat(cmd, &st);
    execve(cmd, args, env);
    write(2, cmd, my_strlen(cmd));
    if ((st.st_mode & S_IFMT) == S_IFREG)
        write(2, ": Exec format error. Binary file not executable.\n", 49);
    if ((st.st_mode & S_IFMT) == S_IFDIR)
        write(2, ": Permission denied.\n", 21);
    free(cmd);
    exit(84);
}

int exec_cmd_ret(char **args, char **env)
{
    pid_t pid = fork();
    int status = 0;

    if (pid < 0)
        return 84;
    if (pid == 0)
        exec_child(args, env);
    wait(&status);
    handle_signal(status);
    if (WIFEXITED(status))
        return WEXITSTATUS(status);
    return 1;
}

void exec_cmd(char **args, char **env)
{
    pid_t pid = fork();
    int status = 0;

    if (pid < 0) {
        perror("fork");
        exit(84);
    } else if (pid == 0) {
        exec_child(args, env);
    } else {
        wait(&status);
        handle_signal(status);
    }
}
