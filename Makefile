##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile
##

CC          = clang
SRC         = SRC/cd.c	\
				SRC/env.c	\
				SRC/execute_commande_isntbuildin.c	\
				SRC/main.c	\
				SRC/utilitaires/mini_printf.c	\
				SRC/utilitaires/my_put_nbr.c	\
				SRC/utilitaires/my_putchar.c	\
				SRC/utilitaires/my_putstr.c	\
				SRC/utilitaires/my_strcat.c	\
				SRC/utilitaires/my_strcmp.c	\
				SRC/utilitaires/my_strdup.c	\
				SRC/utilitaires/my_strlen.c	\
				SRC/utilitaires/my_strncmp.c	\
				SRC/utilitaires/my_strcpy.c	\
				SRC/second_version_of_cd.c \
				SRC/setenv.c	\
				SRC/signaux.c	\
				SRC/unsetenv.c	\
				SRC/error_case_cd.c	\
				SRC/fonction_mysh_two.c	\
				SRC/redirection.c	\
				SRC/piple.c	\
				SRC/execute_buldin_in_piple.c	\
				SRC/save_old_directory.c	\
				SRC/handle_command_and.c	\
				SRC/mandatory_and.c	\
				SRC/handle_command_or.c	\
				SRC/handle_inbitor_slach.c	\
				SRC/mandatory_or.c	\
				SRC/such_inhinibor_simple_quote.c	\
				SRC/such_inhinibor_double_inhibitor.c	\
				SRC/jobs_utils.c	\
				SRC/glob_exp.c		\
				SRC/glob_mtch.c\
				SRC/handle_inbitor_double_quote.c	\
				SRC/handle_inbitor_simple_quote.c	\
				SRC/such_inhinibor_slach.c	\
				SRC/jobs_background.c	\
				SRC/history.c \
				SRC/alias.c \
				SRC/exec_alias.c \
				SRC/return_code.c	\
				SRC/free_space.c	\
				SRC/display_prompt.c	\
				SRC/or.c	\
				SRC/bc_ticks.c	\
				SRC/errors_command_et_or.c	\
				SRC/jobs_reaps.c\

TEST_SRC	= SRC/utilitaires/my_strcmp.c	\
				SRC/utilitaires/my_putchar.c	\
				SRC/utilitaires/my_putstr.c	\
				SRC/utilitaires/my_put_nbr.c	\
				SRC/utilitaires/my_strdup.c	\
				SRC/utilitaires/my_strlen.c	\
				SRC/fonction_mysh_two.c	\
				SRC/utilitaires/my_strncmp.c	\
				SRC/utilitaires/my_strcat.c	\
				SRC/mandatory_and.c	\
				SRC/such_inhinibor_slach.c	\

TEST        = tests/unit_test.c

NAME        = 42sh

TEST_NAME   = unit_tests

all: $(NAME)

$(NAME):
	$(CC) $(SRC) -o $(NAME) -g3

tests_run: fclean
	$(CC) $(TEST_SRC) $(TEST) -o $(TEST_NAME) -lcriterion  -g3 --coverage -I./SRC
	./$(TEST_NAME)

regression:
		bash tests/regression.sh					

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
