/*
** EPITECH PROJECT, 2025
** signal_management
** File description:
** Gestion des signaux pour Minishell1
*/

#include "../my.h"

void handle_sigint(int sig)
{
    write(1, "\n", 1);
    write(1, "\033[1;3;91m$>\033[0m", 16);
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
