/*
** EPITECH PROJECT, 2026
** my.h
** File description:
** MY_H
*/

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <sys/wait.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <signal.h>
    #include <locale.h>
    #include <errno.h>
     #include <fcntl.h>

typedef struct redirect_s {
    int  type;
    char *name;
} redirect_t;

void exec_cmd(char **args, char **env);
char *find_cmd(char *cmd, char **env);
char *read_line(void);
char **parse(char *line);
int handle_builtin(char **av, char *line, char ***env);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
char *my_strdup(char const *src);
int my_putstr(char const *str);
void my_putchar(char c);
char **my_setenv(char **env, char *name, char *value);
int env_len(char **env);
void free_all(char **av, char *line);
int handle_exit(char **av, char *line);
int is_same_var(char *env_line, char *name);
int my_strlen(char const *str);
int handle_env(char **av, char **env);
int handle_cd(char **av, char **env);
char *get_var(char **env, char *name);
int handle_setenv(char **av, char ***env);
int handle_unsetenv(char **av, char ***env);
char **my_unsetenv(char **env, char *name);
char **copy_env(char **env);
int my_strncmp(char const *s1, char const *s2, int n);
void free_env(char **env);
void expand_vars(char **av, char **env);
int my_printf(const char *format, ...);
char **parse_coma(char *line);
char **parse_pipe(char *line);
void exec_pipe(char *line, char **env);
void exec_child(char **args, char **env);
void exec_coma(char *line, char **env);
int has_pipe(char *line);
int has_coma(char *line);
void setup_signals(void);
void restore_signals(void);
void handle_sigint(int sig);
redirect_t *check_redirect(redirect_t *redi, char **av);
void apply_redirect(redirect_t *redi);
void delete_symbol_and_file(redirect_t *redi, char **av);
int dear_and(char *line);
char **parse_and(char *line);
int exec_cmd_ret(char **args, char **env);
#endif
