/*
** EPITECH PROJECT, 2026
** handle_unset.c
** File description:
** handle unsetenv
*/

#include "../../include/my.h"

void print_env(char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        my_putstr(env[i]);
        my_putchar('\n');
        i++;
    }
}

int is_letter(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int is_alnum(char c)
{
    return (is_letter(c) || (c >= '0' && c <= '9'));
}

int is_valid_name(char *name)
{
    int i = 0;

    if (!name || !is_letter(name[0]))
        return 0;
    while (name[i]) {
        if (!is_alnum(name[i]))
            return 0;
        i++;
    }
    return 1;
}

static int cut_setenv(char **av, char **env)
{
    char *s = "setenv: Variable name must contain alphanumeric characters.\n";

    if (!av[1][0] || av[1][0] == '"' || !is_letter(av[1][0])) {
        write(2, "setenv: Variable name must begin with a letter.\n", 49);
        return 1;
    }
    if (av[3]) {
        write(2, "setenv: Too many arguments.\n", 28);
        return 1;
    }
    if (!is_valid_name(av[1])) {
        write(2, s, my_strlen(s));
        return 1;
    }
    return 0;
}

int handle_setenv(char **av, char ***env)
{
    if (my_strcmp(av[0], "setenv") != 0)
        return 0;
    if (!av[1]) {
        print_env(*env);
        return 1;
    }
    cut_setenv(av, *env);
    *env = my_setenv(*env, av[1], av[2] ? av[2] : "");
    return 1;
}
