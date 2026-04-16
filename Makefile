##
## EPITECH PROJECT, 2026
## MAKEFILE
## File description:
## makefile
##

NAME	=	42sh

SRC	=	src/minishell.c\
		src/exec_cmd.c\
		src/find_cmd.c\
		src/parse.c\
		src/read_line.c\
		src/built_in/handle_builin.c\
		src/my_strcpy.c\
		src/my_strcat.c\
		src/my_strcmp.c\
		src/my_putchar.c\
		src/my_putstr.c\
		src/my_strdup.c\
		src/env_len.c\
		src/free_all.c\
		src/my_setenv.c\
		src/built_in/handle_exit.c\
		src/same_var.c\
		src/my_strlen.c\
		src/built_in/handle_env.c\
		src/built_in/handle_cd.c\
		src/get_var.c\
		src/my_unsetenv.c\
		src/built_in/handle_setenv.c\
		src/built_in/handle_unset.c\
		src/copy_env.c\
		src/free_env.c\
		src/my_strncmp.c\
		src/expand_var.c\
		src/my_printf.c\
		src/parse_coma.c\
		src/parse_pipe.c\
		src/exec_pipe.c\
		src/exec_coma.c\
		src/has_pipe.c\
		src/has_coma.c\
		src/signaux.c	\
		src/exec_redirec.c	\
		src/mandatoty_and.c	\

CC	=	clang

LFLAGS	=	--coverage -lcriterion

TESTS_SRC	=	src/my_strlen.c\
			src/my_putchar.c\
			src/my_putstr.c\
			src/my_strcmp.c\
			src/env_len.c\
			src/same_var.c\
			src/my_setenv.c\
			src/my_strcpy.c\
			src/my_strdup.c\
			src/my_strcat.c\
			src/free_env.c\
			src/my_unsetenv.c\
			src/my_strncmp.c\
			src/get_var.c	\

TESTS	=	tests/tests.c\
		tests/test_env.c\
		tests/test_same_var.c\
		tests/test_setenv.c\
		tests/test_line.c\
		tests/test_unsetenv.c\
		tests/test_get_var.c\
		tests/test_strncmp.c\
		tests/test_full_env.c\

all:
	clang -o $(NAME) $(SRC) -g3

clean:
	rm -f $(NAME)

fclean:	clean
	rm -f /src/*~
	rm -f ./Tests/*~
	@rm -f *.gcno
	@rm -f *.gcda
	rm -f unit_tests

coding_style1:
	epiclang ./src/*.c

coding_style2:
	epiclang ./src/built_in/*.c

re:	fclean all

unit_tests: fclean
	clang -o unit_tests $(TESTS) $(TESTS_SRC) $(LFLAGS)

tests_run: unit_tests
	./unit_tests
