/*
** EPITECH PROJECT, 2025
** principale_fonction
** File description:
** main
*/

#include "my.h"

int check_or_errors(principal_function_t *a, char **after_or)
{
    char *before = get_before_or(a->commands[a->i]);

    if (!such_or(a->commands[a->i]))
        return 0;
    if (only_or(a->commands[a->i])) {
        dprintf(2, "Invalid null command.\n");
        return 1;
    }
    if (ends_with_or(a->commands[a->i])) {
        dprintf(2, "Invalid null command.\n");
        return 1;
    }
    if (!before || before[0] == '\0') {
        dprintf(2, "Invalid null command.\n");
        free(before);
        return 1;
    }
    free(before);
    *after_or = get_after_or(a->commands[a->i]);
    return 0;
}
