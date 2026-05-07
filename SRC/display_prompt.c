/*
** EPITECH PROJECT, 2025
** principale_fonction
** File description:
** main
*/

#include "my.h"

void prime_infinity_boucle(principal_function_t *a)
{
    char buf[274];

    reap_finished_jobs(a);
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
