/*
** EPITECH PROJECT, 2025
** fonction
** File description:
** fonction
*/

#include "my.h"

int exec_or_cmd(principal_function_t *a, char **and_cmds,
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

int run_or_loop(principal_function_t *a, char **or_cmds,
    char **env)
{
    int i = 0;

    while (or_cmds[i] != NULL) {
        a->buffer = parse_arg_in_params(or_cmds[i]);
        a->code_de_retour = exec_or_cmd(a, or_cmds, env);
        free(a->buffer);
        if (a->code_de_retour == 0)
            return 0;
        i++;
    }
    return a->code_de_retour;
}

int handle_or(principal_function_t *a, char **env)
{
    char **or_cmds = NULL;

    if (!such_or(a->commands[a->i]))
        return 0;
    or_cmds = parse_or(a->commands[a->i]);
     if (or_cmds[1] == NULL) {
        dprintf(2, "Invalid null command.\n");
        free(or_cmds);
        return 1;
    }
    while (or_cmds[a->j] != NULL)
        a->j++;
    if (a->j == 0) {
        dprintf(2, "Invalid null command.\n");
        free(or_cmds);
        return 1;
    }
    run_or_loop(a, or_cmds, env);
    // for (int j = 0; or_cmds[j]; j++)
    //     free(or_cmds[j]);
    free(or_cmds);
    return 1;
}
