/*
** EPITECH PROJECT, 2025
** add environnement variable
** File description:
** unsetenv
*/

#include "my.h"

// char *return_new_env(char **buffer, char **env)
// {
//     char **env_copy = NULL;
//     int pos = my_getenv(env, buffer[1]);
//     int i = 0;

//     while (env[i] != NULL)
//         i++;
//     env_copy = malloc(sizeof(char *) * (i + 1));
//     i = 0;
//     while (env[i] != NULL) {
//         env_copy[i] = my_strdup(env[i]);
//         i++;
//     }
//     env_copy[i] = NULL;
//     i = pos;
//     while (env_copy[i + 1] != NULL) {
//         env[i] = env_copy[i + 1];
//         i++;
//     }
//     return env[i];
// }

int my_unsetenv_buildin(char **buffer, char **env)
{
    int pos = 0;
    int i = 0;
    char **env_copy = NULL;

    if (buffer[1] == NULL) {
        mini_printf("%s: Too few arguments.\n", buffer[0]);
        return 1;
    }
    pos = my_getenv(env, buffer[1]);
    if (pos == -1)
        return 0;
    i = pos;
    while (env[i + 1] != NULL) {
        env[i] = env[i + 1];
        i++;
    }
    env[i] = NULL;
    return 0;
}
