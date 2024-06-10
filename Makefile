##
## EPITECH PROJECT, 2022
## dragusheen linked_list-library
## File description:
## makefile of the library
##

SRC	=	src/papaya_add.c		\
		src/papaya_create.c		\
		src/papaya_destroy.c	\
		src/papaya_load.c		\
		src/papaya_remove.c		\
		src/papaya_save.c		\
		src/utils/file.c		\
		src/utils/smerge.c		\
		src/utils/tab.c			\
		src/utils/stot.c		\
		src/list/dl_apply.c		\
		src/list/dl_clear.c		\
		src/list/dl_empty.c		\
		src/list/dl_erase.c		\
		src/list/dl_extract.c	\
		src/list/dl_find.c		\
		src/list/dl_insert.c	\
		src/list/dl_length.c	\
		src/list/dl_pop.c		\
		src/list/dl_push.c		\


OBJ	=	$(SRC:%.c=%.o)

NAME	=	libpapaya.a

FLAGS	=	-I./include	\
			-Wall		\
			-Wextra		\
			-Werror		\
			-g3

COMP	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

%.o: %.c
	$(COMP) $(FLAGS) -c -o $@ $<

.PHONY: all clean fclean re

test: re
	@rm -rf test
	$(COMP) $(FLAGS) -o test main.c $(SRC) -L. -lpapaya
