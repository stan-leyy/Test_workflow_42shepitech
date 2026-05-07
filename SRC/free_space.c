/*
** EPITECH PROJECT, 2025
** principale_fonction
** File description:
** main
*/

#include "my.h"

void handle_exit(principal_function_t *a)
{
    if (a->buffer[0] == NULL || my_strcmp(a->buffer[0], "exit") != 0
        || a->buffer[1] != NULL)
        return;
    free(a->buffer);
    free(a->line);
    free(a->old_directory);
    exit(a->code_de_retour);
}
