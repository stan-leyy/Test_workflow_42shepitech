/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** main loop: read, parse, expand, dispatch commands
*/

#include "my.h"

static void run_command(principal_function_t *a, char **env)
{
    if (my_strcmp(a->buffer[0], "alias") == 0) {
        a->code_de_retour = exec_alias_builtin(&a->alias_list, a->buffer);
        return;
    }
    if (my_strcmp(a->buffer[0], "history") == 0) {
        a->code_de_retour = builtin_history(a->history_list, a->buffer);
        return;
    }
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

static void handle_pipe(principal_function_t *a, char **env)
{
    a->piple = parse_piple(a->commands[a->i]);
    execute_pipe(a->piple, env);
    free(a->piple);
}

static void handle_inhibitors(principal_function_t *a, char **env)
{
    char *clean = NULL;
    char *clean_double = NULL;

    if (such_inhibitor_simple_quote(a->commands[a->i])) {
        clean = handle_inhibitor(a->commands[a->i]);
        a->commands[a->i] = clean;
    }
    if (such_inhibitor_double_quote(a->commands[a->i])) {
        clean_double = handle_inhibitor_double_quote(a->commands[a->i], env);
        a->commands[a->i] = clean_double;
    }
}

static void expand_dollar(principal_function_t *a)
{
    char *value = NULL;

    if (strstr(a->commands[a->i], "$?")) {
        value = display_code_of_return(a->commands[a->i],
            a->code_de_retour);
        a->commands[a->i] = value;
    }
}

static void expand_backticks(principal_function_t *a)
{
    char *expanded = NULL;

    if (is_backtick(a->commands[a->i])) {
        expanded = expand_backtick(a->commands[a->i]);
        if (expanded != a->commands[a->i])
            a->commands[a->i] = expanded;
    }
}

void handle_simple_command(principal_function_t *a, char **env)
{
    expand_dollar(a);
    expand_backticks(a);
    a->buffer = parse_arg_in_params(a->commands[a->i]);
    a->buffer = apply_glob_expansion(a->buffer);
    if (is_background(a->buffer)) {
        execute_background(a, a->buffer, env);
        return;
    }
    handle_exit(a);
    run_command(a, env);
    free(a->buffer);
}

static void handle_logic_ops(principal_function_t *a, char **env)
{
    handle_logic_ops_coding_style_t b = {NULL, NULL};

    if (check_or_errors(a, &b.after_or))
        return;
    if (dear_and(a->commands[a->i])) {
        handle_and(a, env);
    } else if (b.after_or != NULL) {
        b.before_or = get_before_or(a->commands[a->i]);
        a->buffer = parse_arg_in_params(b.before_or);
        run_command(a, env);
        free(a->buffer);
        free(b.before_or);
    }
    if (b.after_or != NULL && a->code_de_retour != 0) {
        a->buffer = parse_arg_in_params(b.after_or);
        run_command(a, env);
        free(a->buffer);
    }
    if (b.after_or != NULL)
        free(b.after_or);
}

static void dispatch_command(principal_function_t *a, char **env)
{
    if (dear_and(a->commands[a->i]) || such_or(a->commands[a->i]))
        handle_logic_ops(a, env);
    else if (dear_piple(a->commands[a->i]))
        handle_pipe(a, env);
    else
        handle_simple_command(a, env);
}

static void handle_command(principal_function_t *a, char **env)
{
    char *expanded = process_aliases(a->alias_list, a->commands[a->i]);
    char *original = a->commands[a->i];

    a->commands[a->i] = expanded;
    handle_inhibitors(a, env);
    dispatch_command(a, env);
    if (expanded != original)
        free(expanded);
    a->commands[a->i] = original;
}

static void infinity_boucle(principal_function_t *a, char **env)
{
    char *expanded = NULL;

    prime_infinity_boucle(a);
    if (!a->line || a->line[0] == '\0' || a->line[0] == '\n')
        return;
    add_to_history(&a->history_list, a->line);
    expanded = process_aliases(a->alias_list, a->line);
    a->commands = parse_in_fonction_semicolon(expanded);
    a->i = 0;
    while (a->commands && a->commands[a->i] != NULL) {
        handle_command(a, env);
        a->i++;
    }
    if (expanded != a->line)
        free(expanded);
}

int main(int ac, char **av, char **env)
{
    principal_function_t a = {NULL, 0, NULL, isatty(STDIN_FILENO),
        0, NULL, 0, 0, NULL, 0, NULL, 0, {{0}}, 0, NULL, NULL};

    (void)av;
    if (ac != 1)
        return 84;
    setup_signals();
    while (1)
        infinity_boucle(&a, env);
    free_history(a.history_list);
    if (a.old_directory)
        free(a.old_directory);
    return a.code_de_retour;
}
