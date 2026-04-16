/*
** EPITECH PROJECT, 2026
** find_cmd.c
** File description:
** search commands
*/

#include "../include/my.h"

void create_cmd(char *full, char *cmd, char *dir)
{
    my_strcpy(full, dir);
    my_strcat(full, "/");
    my_strcat(full, cmd);
}

char *find_cmd(char *cmd, char **env)
{
    char *paths = get_var(env, "PATH");
    char *dir;
    char *full = malloc(256);

    if (!paths)
        return NULL;
    if (access(cmd, X_OK) == 0)
        return cmd;
    paths = my_strdup(paths);
    dir = strtok(paths, ":");
    while (dir) {
        create_cmd(full, cmd, dir);
        if (access(full, X_OK) == 0) {
            free(paths);
            return full;
        }
        dir = strtok(NULL, ":");
    }
    free(paths);
    return NULL;
}
