/*
** EPITECH PROJECT, 2025
** principale_fonction
** File description:
** main
*/

#include "my.h"

static void handle_exit(principal_function_t *a)
{
    if (a->buffer[0] == NULL || my_strcmp(a->buffer[0], "exit") != 0
        || a->buffer[1] != NULL)
        return;
    free(a->buffer);
    free(a->line);
    free(a->old_directory);
    exit(a->code_de_retour);
}

void prime_infinity_boucle(principal_function_t *a)
{
    char buf[274];

    if (a->is_interactive) {
        getcwd(buf, sizeof(buf));
        mini_printf("\033[1m~>\033[1;33m%s\033[0m", buf);
        write(1, "$> ", 3);
    }
    if (getline(&a->line, &a->len, stdin) == -1) {
        if (a->is_interactive)
            mini_printf("\n");
        exit(a->code_de_retour);
    }
}

static void run_command(principal_function_t *a, char **env)
{
    a->result = execute_buildin_second(a->buffer,
        &a->old_directory, env, &a->code);
    if (a->result == 0)
        a->code_de_retour = execute_buildin(a->buffer, env,
            &a->old_directory);
    if (a->result == -1)
        a->code_de_retour = 0;
    if (a->result > 0)
        a->code_de_retour = a->result;
}

static void handle_command(principal_function_t *a, char **env)
{
    char *clean = NULL;

    if (such_inhibitor_slach(a->commands[a->i])) {
        clean = handle_inhibitor(a->commands[a->i]);
        a->commands[a->i] = clean;
    }
    if (handle_and(a, env))
        return;
    if (handle_or(a, env))
        return;
    if (dear_piple(a->commands[a->i])) {
        a->piple = parse_piple(a->commands[a->i]);
        execute_pipe(a->piple, env);
        free(a->piple);
        return;
    }
    a->buffer = parse_arg_in_params(a->commands[a->i]);
    handle_exit(a);
    run_command(a, env);
    free(a->buffer);
}

void infinity_boucle(principal_function_t *a, char **env, char **old_directory)
{
    prime_infinity_boucle(a);
    a->commands = parse_in_fonction_semicolon(a->line);
    a->i = 0;
    while (a->commands[a->i] != NULL) {
        handle_command(a, env);
        a->i++;
    }
}

int main(int ac, char **av, char **env)
{
    principal_function_t a = {NULL, 0, NULL, isatty(STDIN_FILENO),
        0, NULL, 0, 0};

    if (ac != 1)
        exit(84);
    setup_signals();
    while (1) {
        infinity_boucle(&a, env, &a.old_directory);
    }
    free(a.old_directory);
    free(a.line);
    return a.code_de_retour;
}
