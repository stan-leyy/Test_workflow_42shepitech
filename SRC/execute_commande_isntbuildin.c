/*
** EPITECH PROJECT, 2025
** execute_not_a buildin
** File description:
** execute
*/

#include "my.h"

static void *my_getenv_path(char **env)
{
    int i = 0;
    char *path = NULL;

    while (env[i] != NULL) {
        if (my_strncmp(env[i], "PATH", 4) == 0) {
            path = my_strdup(env[i] + 5);
        }
        i++;
    }
    return (path);
}

char *dear_command(char *com, char **env)
{
    command_t a = {NULL, NULL, NULL, NULL};

    if (contains_barre(com))
        return com;
    a.path_env = my_getenv_path(env);
    if (a.path_env == NULL)
        return NULL;
    a.path_copy = my_strdup(a.path_env);
    a.token = strtok(a.path_copy, ":");
    while (a.token != NULL) {
        a.path = cons_path(a.token, com);
        if (access(a.path, X_OK) == 0) {
            free(a.path_copy);
            return a.path;
        }
        free(a.path);
        a.token = strtok(NULL, ":");
    }
    free(a.path_copy);
    return NULL;
}

int contains_barre(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '/')
            return 1;
        i++;
    }
    return 0;
}

char *cons_path(char *token, char *com)
{
    path_t a = {0, 0, 0, 0};

    while (token[a.token_size] != '\0')
        a.token_size++;
    while (com[a.com_size] != '\0')
        a.com_size++;
    a.path = malloc(a.token_size + 1 + a.com_size + 1);
    while (a.i < a.token_size) {
        a.path[a.i] = token[a.i];
        a.i++;
    }
    a.path[a.i] = '/';
    a.i++;
    while (a.j < a.com_size) {
        a.path[a.i] = com[a.j];
        a.i++;
        a.j++;
    }
    a.path[a.i] = '\0';
    return a.path;
}

static void handle_sigsegv(int status)
{
    mini_printf("Segmentation fault");
    if (WCOREDUMP(status))
        mini_printf(" (core dumped)");
    write(1, "\n", 1);
}

int signal_verification(char **av, char **env)
{
    int status = execute_command_innt_buildin(av, env);
    int sign = 0;

    if (WIFEXITED(status)) {
        return WEXITSTATUS(status);
    }
    if (WIFSIGNALED(status)) {
        sign = WTERMSIG(status);
        if (sign == SIGSEGV)
            handle_sigsegv(status);
        if (sign == SIGQUIT)
            return 128 + sign;
    }
    return 1;
}

static int coding_style(char **av, char **env)
{
    execute_t a = {dear_command(av[0], env), 0, 0};

    if (a.com == NULL) {
        mini_printf("%s: Command not found.\n", av[0]);
        return -1;
    }
    return 0;
}

static void execute_child(execute_t *a, redirect_t *redi, char **av, char **env)
{
    restore_signals();
    apply_redirect(redi);
    delete_symbol_and_file(redi, av);
    execve(a->com, av, env);
    mini_printf("%s: Command not found.\n", a->com);
    exit(1);
}

static int fork_and_wait(execute_t *a, redirect_t *redi, char **av, char **env)
{
    a->pid = fork();
    if (a->pid == -1) {
        perror("fork");
        exit(1);
    }
    a->com = dear_command(av[0], env);
    if (a->pid == 0)
        execute_child(a, redi, av, env);
    waitpid(a->pid, &a->status, 0);
    if (!contains_barre(av[0]))
        free(a->com);
    return a->status;
}

int execute_command_innt_buildin(char **av, char **env)
{
    execute_t a = {NULL, 0, 0};
    redirect_t redi = {0, NULL};

    if (coding_style(av, env) == -1)
        return 1;
    check_redirect(&redi, av);
    if (redi.type == -1) {
        dprintf(2, "Missing name for redirect.\n");
        return 1;
    }
    return fork_and_wait(&a, &redi, av, env);
}
