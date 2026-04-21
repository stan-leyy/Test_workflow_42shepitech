/*
** EPITECH PROJECT, 2025
** piple_fonction
** File description:
** piple
*/


#include "my.h"

int execute_builtin_in_pipe_coding_style(char **av, char **env)
{
    int i = 0;

    if (av[1] == NULL) {
        while (env[i] != NULL) {
            mini_printf("%s\n", env[i]);
            i++;
        }
    } else {
        if (tcsh_retour(av, env) == 0)
            my_setenv_buildin(av, env);
    }
    return 1;
}

int execute_builtin_in_pipe(char **av, char **env)
{
    if (av[0] == NULL)
        return 0;
    if (my_strcmp(av[0], "env") == 0) {
        display_environnement(env);
        return 1;
    }
    if (my_strcmp(av[0], "setenv") == 0) {
        if (execute_builtin_in_pipe_coding_style(av, env))
            return 1;
    }
    if (my_strcmp(av[0], "pwd") == 0) {
        dprintf(2, "Invalid null command.\n");
        return 1;
    }
    if (my_strcmp(av[0], "unsetenv") == 0) {
        dprintf(2, "Commande nulle incorrecte.\n");
        return 1;
    }
    return 0;
}
