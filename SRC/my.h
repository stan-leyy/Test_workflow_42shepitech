/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my.h
*/

#ifndef __MY_H_
    #define __MY_H_
    #include <stdio.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <signal.h>
    #include <locale.h>
    #include <errno.h>

typedef struct principal_function {
    char *line;
    size_t len;
    char **buffer;
    int is_interactive;
    int code_de_retour;
    char *old_directory;
    int result;
    int code;
    char **commands;
    int i;
    char **piple;
    int j;
}principal_function_t;

typedef struct command {
    char *path_env;
    char *path_copy;
    char *token;
    char *path;
}command_t;

typedef struct path {
    int token_size;
    int com_size;
    int i;
    int j;
    char *path;
}path_t;

typedef struct execute {
    char *com;
    pid_t pid;
    int status;
}execute_t;

typedef struct my_setenv
{
    int pos;
    char *new_ligne;
    int i;

}my_setenv_t;

typedef struct redirect
{
    int type;
    char *name;
}redirect_t;

typedef struct pipe_exec {
    int fd[2];
    pid_t pid_left;
    pid_t pid_right;
    int status;
} pipe_exec_t;

typedef struct pipe_chain {
    int prev_fd;
    int fd[2];
    int i;
    int status;
} pipe_chain_t;

typedef struct execute_pipe_coding_style {
    pipe_chain_t p;
    char **av;
    int count;
    pid_t pids[64];
}execute_pipe_coding_style_t;
int execute_pipe(char **pipe_cmds, char **env);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int mini_printf(const char *format, ...);
int my_strcmp(char *a, char *b);
void display_environnement(char **env);
char **parse_arg_in_params(char *line);
int execute_buildin(char **buffer, char **env, char **old_directory);
int execute_command_innt_buildin(char **av, char **env);
char *cons_path(char *dir, char *com);
char *my_strdup(char *src);
int contains_barre(char *str);
int my_strncmp(char *s1, char *s2, int n);
int my_strlen(char const *str);
void change_directory(char **av, char **old_directoty);
int buildin_cd(char **av, char **env, char **old_directory);
int execute_buildin_second(char **buffer, char **old_directory,
    char **env, int *code);
char *recup_directory(void);
void setup_signals(void);
void restore_signals(void);
int signal_verification(char **av, char **env);
char *my_setenv_buildin(char **buffer, char **env);
int my_getenv(char **env, char *var_name);
int my_unsetenv_buildin(char **buffer, char **env);
char *my_strcpy(char *dest, char *src);
char *my_strcat(char *dest, char *src);
void two_cd_home(char **av, char **env);
void *my_own_getenv(char **env);
int tcsh_retour(char **buffer, char **env);
int buildin_cd_error_case(char **av);
char *checker(char *line);
char **parse_in_fonction_semicolon(char *line);
void apply_redirect(redirect_t *redi);
void delete_symbol_and_file(redirect_t *redi, char **av);
redirect_t *check_redirect(redirect_t *redi, char **av);
int dear_piple(char *line);
char **parse_in_fonction_piple(char *line);
int execute_pipe(char **pipe_cmds, char **env);
char **parse_in_fonction_piple(char *line);
char *dear_command(char *com, char **env);
char **parse_piple(char *line);
int execute_builtin_in_pipe(char **av, char **env);
void save_old_directory(char **old_directory);
int handle_and(principal_function_t *a, char **env);
int dear_and(char *line);
char **parse_and(char *line);
int handle_or(principal_function_t *a, char **env);
char **parse_or(char *line);
int such_or(char *line);
int such_inhibitor_slach(char *line);
char *handle_inhibitor(char *line);
int copy_string(char *src, char *dest);
#endif
