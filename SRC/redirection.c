/*
** EPITECH PROJECT, 2025
** implemante fonction check redirection
** File description:
** redirection
*/

#include "my.h"

redirect_t *verification(redirect_t *redi, char *c)
{
    redi->type = 0;
    if (my_strcmp(c, ">") == 0)
        redi->type = 1;
    if (my_strcmp(c, ">>") == 0)
        redi->type = 2;
    if (my_strcmp(c, "<") == 0)
        redi->type = 3;
    if (my_strcmp(c, "<<") == 0)
        redi->type = 4;
    return redi;
}

redirect_t *check_redirect(redirect_t *redi, char **av)
{
    int i = 0;

    while (av[i] != NULL) {
        verification(redi, av[i]);
        if (redi->type == 1 || redi->type == 2 ||
            redi->type == 3 || redi->type == 4) {
            if (av[i + 1] == NULL) {
                redi->type = -1;
                return redi;
            }
            redi->name = my_strdup(av[i + 1]);
            break;
        }
        i++;
    }
    return redi;
}

int delete_symbol_coding(redirect_t *redi, char **av)
{
    int i = 0;

    while (av[i] != NULL) {
        verification(redi, av[i]);
        if (redi->type != 0)
            return i;
        i++;
    }
    return -1;
}

void delete_symbol_and_file(redirect_t *redi, char **av)
{
    int j = delete_symbol_coding(redi, av);

    if (j == -1)
        return;
    while (av[j + 2] != NULL) {
        av[j] = av[j + 2];
        j++;
    }
    av[j] = NULL;
    av[j + 1] = NULL;
    return;
}

void apply_redirect(redirect_t *redi)
{
    int fd = 0;

    if (redi->type == 1)
        fd = open(redi->name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (redi->type == 2)
        fd = open(redi->name, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (redi->type == 3)
        fd = open(redi->name, O_RDONLY);
    if (fd == -1) {
        perror(redi->name);
        return;
    }
    if (redi->type == 1 || redi->type == 2)
        dup2(fd, STDOUT_FILENO);
    if (redi->type == 3)
        dup2(fd, STDIN_FILENO);
    close(fd);
}
