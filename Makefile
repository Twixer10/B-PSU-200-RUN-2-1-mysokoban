##
## EPITECH PROJECT, 2020
## makefile exe
## File description:
## fct
##

SRC	=		src/main.c	\
			src/map_manager/load_map.c	\
			src/map_manager/area_manager.c	\
			src/map_manager/map_manager.c	\
			src/game/game_manager.c	\
			src/game/moov_manager.c	\
			src/game/win.c	\

CFLAGS	=	-W -Wextra -Wall -Werror -g3

LFLAGS	=	-L lib/ -lmy -l ncurses

IFLAGS	=	-I include/

NAME	=	my_sokoban

all:
	make -C lib/my all
	gcc -o $(NAME) $(SRC) $(IFLAGS) $(LFLAGS) $(CFLAGS)

clean:
	make -C lib/my clean
	rm -f *~
	rm -f *.o

fclean:
	make -C lib/my fclean
	rm -f $(NAME)

re:	fclean all
	make -C lib/my re
