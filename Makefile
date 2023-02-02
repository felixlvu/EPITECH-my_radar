##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC = ./src/main.c \
	  ./src/elements.c \
	  ./src/flag_h.c \
	  ./src/start_radar.c \
	  ./src/print_element.c \

OBJ = $(SRC:.c=.o)

LIB = -L ./lib/my/ -lmy

CFLAGS = -I ./include/ -lcsfml-graphics -lcsfml-window -lcsfml-system

NAME = my_radar

$(NAME): $(OBJ)
	make -C ./lib/my/
	gcc $(OBJ) -o $(NAME) $(CFLAGS) $(LIB)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/my/

re: fclean all

debug:	CFLAGS += -g3
debug:	re
