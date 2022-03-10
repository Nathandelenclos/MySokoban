##
## EPITECH PROJECT, 2021
## Day12
## File description:
## makefile
##

MAIN	=	main.c	\

SRC	=	map_manager.c	\
		manage_key.c	\
		move_player.c	\
		victory_loose.c	\
		get_element.c	\
		game_error.c	\

OBJ	=	$(MAIN:.c=.o) $(SRC:.c=.o)

TEST_FILE	=		\

NAME	=	my_sokoban

LIB	=	-lncurses	\
		-llist	\
		-lmy

CFLAGS	=	-g

all:	buildlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C ./lib/my/ fclean
	make -C ./lib/linked_list/ fclean

re:	fclean all

exe:
	./$(NAME)

buildlib:
	make -C ./lib/my/
	make -C ./lib/linked_list/

tests_run:
	gcc -o unit_tests $(SRC) $(TEST_FILE) -L./lib $(LIB)
	./unit_tests
	rm unit_tests*

$(NAME):	$(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -L./lib $(LIB)
