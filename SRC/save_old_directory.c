/*
** EPITECH PROJECT, 2025
** fonction
** File description:
** fonction
*/

#include "my.h"

void save_old_directory(char **old_directory)
{
    char current_path[200];

    if (getcwd(current_path, sizeof(current_path)) != NULL) {
        if (*old_directory != NULL)
            free(*old_directory);
        *old_directory = my_strdup(current_path);
    }
}
