/*
** EPITECH PROJECT, 2026
** test_setenv.c
** File description:
** test setenv
*/

#include "../include/my.h"
#include <criterion/criterion.h>
#include <string.h>

char **my_setenv(char **env, char *name, char *value);
int env_len(char **env);
void free_env(char **env);

Test(setenv, add_variable)
{
    char **env = malloc(sizeof(char *) * 1);

    env[0] = NULL;
    env = my_setenv(env, "TEST", "123");
    cr_assert_eq(env_len(env), 1);
    cr_assert_str_eq(env[0], "TEST=123");
    free_env(env);
}

Test(setenv, replace_variable)
{
    char **env = malloc(sizeof(char *) * 2);

    env[0] = strdup("TEST=old");
    env[1] = NULL;
    env = my_setenv(env, "TEST", "new");
    cr_assert_str_eq(env[0], "TEST=new");
    free_env(env);
}
