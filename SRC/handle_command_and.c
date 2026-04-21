/*
** EPITECH PROJECT, 2025
** fonction
** File description:
** fonction
*/

#include "my.h"

int exec_and_cmd(principal_function_t *a, char **and_cmds,
    char **env)
{
    a->result = execute_buildin_second(a->buffer, &a->old_directory,
        env, &a->code);
    if (a->result == 0)
        return execute_buildin(a->buffer, env, &a->old_directory);
    if (a->result == -1)
        return 0;
    return a->result;
}

int run_and_loop(principal_function_t *a, char **and_cmds,
    char **env)
{
    int i = 0;

    while (and_cmds[i] != NULL) {
        a->buffer = parse_arg_in_params(and_cmds[i]);
        a->code_de_retour = exec_and_cmd(a, and_cmds, env);
        free(a->buffer);
        if (a->code_de_retour != 0)
            return a->code_de_retour;
        i++;
    }
    return 0;
}

int handle_and(principal_function_t *a, char **env)
{
    char **and_cmds = NULL;

    if (!dear_and(a->commands[a->i]))
        return 0;
    and_cmds = parse_and(a->commands[a->i]);
    if (and_cmds[1] == NULL) {
        dprintf(2, "Invalid null command.\n");
        free(and_cmds);
        return 1;
    }
    while (and_cmds[a->j] != NULL)
        a->j++;
    if (a->j == 0) {
        dprintf(2, "Invalid null command.\n");
        free(and_cmds);
        return 1;
    }
    run_and_loop(a, and_cmds, env);
    free(and_cmds);
    return 1;
}
