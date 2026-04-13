##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile
##

CC          = clang
SRC         = SRC/builtins/cd.c	\
				SRC/builtins/env.c	\
				SRC/builtins/error_case_cd.c	\
				SRC/builtins/save_old_directory.c	\
				SRC/builtins/second_version_of_cd.c	\
				SRC/builtins/setenv.c	\
				SRC/builtins/unsetenv.c	\
				SRC/function_for_minishell2/execute_commande_isntbuildin.c	\
				SRC/function_for_minishell2/fonction_mysh_two.c	\
				SRC/function_for_minishell2/signaux.c	\
				SRC/piple/execute_buldin_in_piple.c	\
				SRC/piple/piple.c	\
				SRC/redirection/redirection.c	\
				SRC/utilitaire_piscine/mini_printf.c	\
				SRC/utilitaire_piscine/my_put_nbr.c	\
				SRC/utilitaire_piscine/my_putchar.c	\
				SRC/utilitaire_piscine/my_putstr.c	\
				SRC/utilitaire_piscine/my_strcat.c	\
				SRC/utilitaire_piscine/my_strcmp.c	\
				SRC/utilitaire_piscine/my_strcpy.c	\
				SRC/utilitaire_piscine/my_strdup.c	\
				SRC/utilitaire_piscine/my_strncmp.c	\
				SRC/main.c \
				SRC/utilitaire_piscine/my_strlen.c \

TEST_SRC	= SRC/utilitaire_piscine/my_strcmp.c	\
				SRC/utilitaire_piscine/my_putchar.c \
				SRC/utilitaire_piscine/my_putstr.c	\
				SRC/utilitaire_piscine/my_put_nbr.c	\
				SRC/utilitaire_piscine/my_strdup.c	\
				SRC/utilitaire_piscine/my_strlen.c	\
				SRC/function_for_minishell2/fonction_mysh_two.c	\

TEST        = tests/unit_test.c
NAME        = 42sh
TEST_NAME   = unit_tests

all: $(NAME)

$(NAME):
	$(CC) $(SRC) -o $(NAME) -g3

tests_run: fclean
	$(CC) $(TEST_SRC) $(TEST) -o $(TEST_NAME) -lcriterion  -g3 --coverage -I./SRC
	./$(TEST_NAME)

clean:
	rm -f *.o
	rm -f SRC/*.o
	rm -f tests/*.o
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST_NAME)

re: fclean all
