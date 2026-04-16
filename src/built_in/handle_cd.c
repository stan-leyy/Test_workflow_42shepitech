/*
** EPITECH PROJECT, 2026
** handle_cd.c
** File description:
** handle cd
*/

#include "../../include/my.h"

void cd_minus(char *oldpwd)
{
    if (!oldpwd || oldpwd[0] == '\0') {
        write(2, ": No such file or directory.\n", 29);
        return;
    }
    if (chdir(oldpwd) == -1)
        perror("cd");
}

void cd_home(char **env)
{
    char *home = get_var(env, "HOME");

    if (!home) {
        write(2, "cd: HOME not set\n", 17);
        return;
    }
    chdir(home);
}

int handle_cd(char **av, char **env)
{
    static char oldpwd[1024];
    char cwd[1024];
    struct stat st;

    stat(av[1], &st);
    if (my_strcmp(av[0], "cd") != 0)
        return 0;
    getcwd(cwd, sizeof(cwd));
    if ((st.st_mode & S_IFMT) == S_IFREG) {
        write(2, av[1], my_strlen(av[1]));
        write(2, ": Not a directory.\n", 19);
    }
    if (!av[1] || my_strcmp(av[1], "~") == 0)
        cd_home(env);
    else if (my_strcmp(av[1], "-") == 0)
        cd_minus(oldpwd);
    else
        chdir(av[1]);
    my_strcpy(oldpwd, cwd);
    return 1;
}
