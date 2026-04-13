/*
** EPITECH PROJECT, 2025
** fonction
** File description:
** fonction
*/

#include "../my.h"

void *my_own_getenv(char **env)
{
    int i = 0;
    char *path = NULL;

    while (env[i] != NULL) {
        if (my_strncmp(env[i], "HOME", 4) == 0) {
            path = my_strdup(env[i] + 5);
        }
        i++;
    }
    return (path);
}

static void my_own_getenv_pwd(char **env)
{
    int i = 0;
    char current_path[200];
    char *new_pwd = NULL;
    int pwd_len = 0;
    int path_len = 0;

    if (getcwd(current_path, sizeof(current_path)) == NULL)
        return;
    while (env[i] != NULL) {
        if (my_strncmp(env[i], "PWD=", 4) == 0) {
            path_len = my_strlen(current_path);
            new_pwd = malloc(sizeof(char) * (4 + path_len + 1));
            my_strcpy(new_pwd, "PWD=");
            my_strcat(new_pwd, current_path);
            env[i] = new_pwd;
            return;
        }
        i++;
    }
}

static void buildin_cd_decouper(char **av, char **env)
{
    char *path = av[1];

    path = my_own_getenv(env);
    if (chdir(path) == 0)
        my_own_getenv_pwd(env);
    free(path);
}

int buildin_cd(char **av, char **env, char **old_directory)
{
    char *path = av[1];

    if (path != NULL && path[0] == '-')
        return 0;
    if (buildin_cd_error_case(av) == -1)
        return 1;
    save_old_directory(old_directory);
    if (path == NULL) {
        buildin_cd_decouper(av, env);
        return 0;
    }
    if (chdir(path) == 0) {
        my_own_getenv_pwd(env);
        return 0;
    } else if (errno == ENOTDIR)
        mini_printf("%s: Not a directory.\n", path);
    else
        mini_printf("%s: No such file or directory.\n", path);
    return 1;
}

static void pwd(char **bufer)
{
    char filepath[200];

    if (getcwd(filepath, sizeof(filepath)) != NULL) {
        if (bufer[1] != NULL) {
            mini_printf("%s: ignoring non-option arguments\n", bufer[0]);
            mini_printf("%s\n", filepath);
        } else {
            mini_printf("%s\n", filepath);
        }
    } else {
        perror("getcwd");
    }
}

char **parse_arg_in_params(char *line)
{
    int i = 0;
    char *token = NULL;
    char **buffer = malloc(sizeof(char *) * 64);

    token = strtok(line, " \t\n");
    for (; token != NULL && i < 63; i++) {
        buffer[i] = token;
        token = strtok(NULL, " \t\n");
    }
    buffer[i] = NULL;
    return buffer;
}

static int execute_buildin_prime(char **buffer, char **env)
{
    if (my_strcmp(buffer[0], "exit") == 0 && buffer[1] != NULL) {
        mini_printf("%s: Expression Syntax.\n", buffer[0]);
        return 1;
    }
    return 0;
}

int execute_buildin(char **buffer, char **env, char **old_directory)
{
    int result = 0;

    if (buffer[0] == NULL)
        return 0;
    result = execute_buildin_prime(buffer, env);
    if (result != 0)
        return result;
    if (my_strcmp(buffer[0], "pwd") == 0) {
        pwd(buffer);
        return 0;
    }
    if (my_strcmp(buffer[0], "cd") == 0) {
        buildin_cd(buffer, env, old_directory);
        return 0;
    }
    if (my_strcmp(buffer[0], "env") == 0) {
        display_environnement(env);
        return 0;
    }
    return signal_verification(buffer, env);
}

static int execute_buildin_second_prime(char **buffer, char **old_directory)
{
    if (my_strcmp(buffer[0], "cd") == 0
        && buffer[1] != NULL && buffer[1][0] == '-') {
        change_directory(buffer, old_directory);
        return -1;
    }
    return 0;
}

int execute_buildin_second(char **buffer, char **old_directory,
    char **env, int *code)
{
    if (buffer[0] == NULL)
        return 0;
    if (execute_buildin_second_prime(buffer, old_directory) == -1)
        return -1;
    if (my_strcmp(buffer[0], "setenv") == 0) {
        *code = tcsh_retour(buffer, env);
        if (*code == 0)
            my_setenv_buildin(buffer, env);
        return *code == 0 ? -1 : *code;
    }
    if (my_strcmp(buffer[0], "unsetenv") == 0) {
        *code = my_unsetenv_buildin(buffer, env);
        return *code == 0 ? -1 : *code;
    }
    if (my_strcmp(buffer[0], "cd") == 0
        && buffer[1] != NULL && my_strcmp(buffer[1], "~") == 0) {
        two_cd_home(buffer, env);
        return -1;
    }
    return 0;
}
