##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile of infinadd
##

NAME	=	mysh

SRC	=	src/main.c 							\
		src/loop.c 							\
		src/check_builtin.c 				\
		src/show_prompt.c 					\
		src/functions/my_cd.c 				\
		src/functions/cd_func.c 			\
		src/functions/cd_dash.c 			\
		src/functions/my_env.c 				\
		src/functions/unset_env.c 			\
		src/functions/functions.c 			\
		src/functions/my_exit.c				\
		src/str_to_array/my_strtowarr.c 	\
		src/str_to_array/word_to_array.c	\
		src/split/my_split.c 				\
		src/split/split_by_chars.c 			\
		src/linked_lists/linked_functions.c \
		src/linked_lists/init_list.c 		\
		src/linked_lists/get_env_values.c 	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include/ -pedantic -g3

LDLIBS	=	-L./lib/ -lmy

all:		$(NAME)

$(NAME):	make_lib $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDLIBS)

make_lib:
		$(MAKE) -C lib/my

clean:
		rm -f $(OBJ)
		$(MAKE) clean -C lib/my/

fclean: 	clean
		rm -f $(NAME)
		$(MAKE) fclean -C lib/my

run_tests:

re:		fclean all
		$(MAKE) re -C lib/my
