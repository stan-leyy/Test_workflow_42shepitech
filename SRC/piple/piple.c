/*
** EPITECH PROJECT, 2025
** piple_fonction
** File description:
** piple
*/


#include "../my.h"

int dear_piple(char *line)
{
    int i = 0;

    while (line[i] != '\0') {
        if (line[i] == '|')
            return 1;
        i++;
    }
    return 0;
}

static int line_emphy(char **piple_command)
{
    int i = 0;

    while (piple_command[i] != NULL) {
        if (piple_command[i][0] == '\0') {
            dprintf(2, "Invalid null command.\n");
            return 1;
        }
        i++;
    }
    return 0;
}

char **parse_piple(char *line)
{
    int i = 0;
    int j = strlen(line) - 1;
    char *token = NULL;
    char **buffer = malloc(sizeof(char *) * 64);

    while (j >= 0 && (line[j] == ' ' || line[j] == '\t' || line[j] == '\n'))
        j--;
    if (line[j] == '|') {
        buffer[0] = "";
        buffer[1] = NULL;
        return buffer;
    }
    token = strtok(line, "|");
    for (; token != NULL && i < 63; i++) {
        buffer[i] = checker(token);
        token = strtok(NULL, "|");
    }
    buffer[i] = NULL;
    return buffer;
}

int count_cmds(char **pipe_cmds)
{
    int i = 0;

    while (pipe_cmds[i] != NULL)
        i++;
    return i;
}

void execute_child_pipe(int prev_fd, int next_fd, char **av, char **env)
{
    restore_signals();
    if (prev_fd != -1) {
        dup2(prev_fd, STDIN_FILENO);
        close(prev_fd);
    }
    if (next_fd != -1) {
        dup2(next_fd, STDOUT_FILENO);
        close(next_fd);
    }
    if (execute_builtin_in_pipe(av, env))
        exit(0);
    execve(dear_command(av[0], env), av, env);
    mini_printf("%s: Command not found.\n", av[0]);
    exit(1);
}

static void parent_manage_fds(pipe_chain_t *p, char **pipe_cmds)
{
    if (p->prev_fd != -1)
        close(p->prev_fd);
    if (pipe_cmds[p->i + 1] != NULL)
        close(p->fd[1]);
    p->prev_fd = pipe_cmds[p->i + 1] != NULL ? p->fd[0] : -1;
}

static void wait_all_pids(pid_t *pids, int count, int *status)
{
    int i = 0;

    while (i < count) {
        waitpid(pids[i], status, 0);
        i++;
    }
}

static void run_pipe_loop(execute_pipe_coding_style_t *a,
    char **pipe_cmds, char **env)
{
    while (pipe_cmds[a->p.i] != NULL) {
        if (pipe_cmds[a->p.i + 1] != NULL)
            pipe(a->p.fd);
        a->av = parse_arg_in_params(pipe_cmds[a->p.i]);
        a->pids[a->p.i] = fork();
        if (a->pids[a->p.i] == 0)
            execute_child_pipe(a->p.prev_fd,
                pipe_cmds[a->p.i + 1] != NULL ? a->p.fd[1] : -1,
                a->av, env);
        parent_manage_fds(&a->p, pipe_cmds);
        free(a->av);
        a->p.i++;
    }
}

int execute_pipe(char **pipe_cmds, char **env)
{
    execute_pipe_coding_style_t a = {{-1, {0, 0}, 0, 0},
        NULL, count_cmds(pipe_cmds)};

    if (a.count == 0) {
        dprintf(2, "Invalid null command.\n");
        return 1;
    }
    if (line_emphy(pipe_cmds))
        return 1;
    run_pipe_loop(&a, pipe_cmds, env);
    wait_all_pids(a.pids, a.count, &a.p.status);
    return WEXITSTATUS(a.p.status);
}
