/*
** EPITECH PROJECT, 2025
** add environnement variable
** File description:
** setenv
*/

#include "../my.h"

int my_getenv(char **env, char *var_name)
{
    int i = 0;
    int j = my_strlen(var_name);

    while (env[i] != NULL) {
        if (my_strncmp(env[i], var_name, j) == 0 && env[i][j] == '=') {
            return i;
        }
        i++;
    }
    return -1;
}

char *free_line(int *pos, char **env, char **buffer)
{
    int n = my_strlen(buffer[1]);
    int m = my_strlen(buffer[2]);
    char *new_line = NULL;

    *pos = my_getenv(env, buffer[1]);
    new_line = malloc(sizeof(char) * (n + m + 2));
    my_strcpy(new_line, buffer[1]);
    my_strcat(new_line, "=");
    my_strcat(new_line, buffer[2]);
    return new_line;
}

char *free_line2(int *pos, char **env, char **buffer)
{
    int n = my_strlen(buffer[1]);
    char *new_line = NULL;

    *pos = my_getenv(env, buffer[1]);
    new_line = malloc(sizeof(char) * (n + 2));
    my_strcpy(new_line, buffer[1]);
    my_strcat(new_line, "=");
    return new_line;
}

static int decoup_function(char **buffer, char **env)
{
    int i = 0;

    if (buffer[1] == NULL) {
        for (; env[i] != NULL; i++)
            mini_printf("%s\n", env[i]);
        return -1;
    }
    if (buffer[1] && buffer[2] && buffer[3] != NULL) {
        write(2, "setenv: Too many arguments.\n", 28);
        return 1;
    }
    return 0;
}

static int decoup_function2(char **buffer, char **env)
{
    if (buffer[1][0] >= '0' && buffer[1][0] <= '9') {
        mini_printf("setenv: Variable name must begin");
        mini_printf(" with a letter.\n");
        return -1;
    }
    return 0;
}

static int decoup_function3(char **buffer)
{
    int i = 0;

    while (buffer[1][i] != '\0') {
        if (!((buffer[1][i] >= 'a' && buffer[1][i] <= 'z') ||
                (buffer[1][i] >= 'A' && buffer[1][i] <= 'Z') ||
                (buffer[1][i] >= '0' && buffer[1][i] <= '9') ||
                buffer[1][i] == '_')) {
            mini_printf("setenv: Variable name must ");
            mini_printf("contain alphanumeric characters.\n");
            return -1;
        }
        i++;
    }
    return 0;
}

int tcsh_retour(char **buffer, char **env)
{
    int result = decoup_function(buffer, env);

    if (result == -1)
        return 0;
    if (result == 1)
        return 1;
    if (decoup_function2(buffer, env) == -1)
        return 1;
    if (decoup_function3(buffer) == -1)
        return 1;
    return 0;
}

char *my_setenv_buildin(char **buffer, char **env)
{
    my_setenv_t a = {0, NULL, 0};

    if (buffer[1] == NULL)
        return NULL;
    if (buffer[2] != NULL)
        a.new_ligne = free_line(&a.pos, env, buffer);
    else
        a.new_ligne = free_line2(&a.pos, env, buffer);
    if (a.pos != -1) {
        env[a.pos] = a.new_ligne;
    } else {
        while (env[a.i] != NULL)
            a.i++;
        env[a.i] = a.new_ligne;
        env[a.i + 1] = NULL;
    }
    return a.new_ligne;
}
