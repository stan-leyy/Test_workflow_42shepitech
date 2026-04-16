/*
** EPITECH PROJECT, 2026
** test_unsetenv.c
** File description:
** test unsetenv
*/

#include "../include/my.h"
#include <criterion/criterion.h>

char **my_unsetenv(char **env, char *name);
int env_len(char **env);
void free_env(char **env);

Test(unsetenv, remove_variable)
{
    char **env = malloc(sizeof(char *) * 3);

    env[0] = strdup("A=1");
    env[1] = strdup("B=2");
    env[2] = NULL;
    env = my_unsetenv(env, "A");
    cr_assert_eq(env_len(env), 1);
    cr_assert_str_eq(env[0], "B=2");
    free_env(env);
}

Test(unsetenv, remove_nonexistent)
{
    char **env = malloc(sizeof(char *) * 2);

    env[0] = strdup("A=1");
    env[1] = NULL;
    env = my_unsetenv(env, "X");
    cr_assert_eq(env_len(env), 1);
    free_env(env);
}
