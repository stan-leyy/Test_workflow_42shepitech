/*
** EPITECH PROJECT, 2025
** change
** File description:
** change directory
*/

#include "../my.h"

char *recup_directory(void)
{
    char *old_directory = malloc(62);

    if (getcwd(old_directory, 62) != NULL)
        return old_directory;
    return NULL;
}

void change_directory(char **av, char **old_directoty)
{
    char path[200];

    if (*old_directoty == NULL) {
        mini_printf("cd: No such file or directory.\n");
        return;
    }
    if (getcwd(path, sizeof(path)) != NULL) {
        if (av[1] != NULL) {
            mini_printf("~%s\n", *old_directoty);
            chdir(*old_directoty);
            *old_directoty = my_strdup(path);
        }
    }
}

void two_cd_home(char **av, char **env)
{
    char *home = my_own_getenv(env);

    chdir(home);
    free(home);
}
