/*
** EPITECH PROJECT, 2025
** signal_management
** File description:
** Gestion des signaux pour Minishell1
*/

#include "../include/my.h"

void handle_sigint(int sig)
{
    char buf[274];

    getcwd(buf, sizeof(buf));
    my_printf("\n\033[1m~>\033[1;33m%s\033[0m", buf);
    write(1, "$> ", 3);
}

void setup_signals(void)
{
    signal(SIGINT, handle_sigint);
    signal(SIGQUIT, SIG_IGN);
}

void restore_signals(void)
{
    signal(SIGINT, SIG_DFL);
    signal(SIGQUIT, SIG_DFL);
}
