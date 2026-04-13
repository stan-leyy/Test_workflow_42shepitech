/*
** EPITECH PROJECT, 2025
** add environnement variable
** File description:
** unsetenv
*/

#include "../my.h"

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
