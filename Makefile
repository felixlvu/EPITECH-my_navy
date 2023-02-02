##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC = ./src/main.c \
	  ./src/flag_h.c \
	  ./src/create_all_map.c \
	  ./src/read_pos.c \
	  ./src/read_pos1_ext.c \
	  ./src/read_pos2.c \
	  ./src/read_pos2_ext.c \
	  ./src/print_base.c \
	  ./src/create_signal_binary.c \
	  ./src/error_gest_coo.c \
	  ./src/error_gest_check_validcoo.c \
	  ./src/attack.c \
	  ./src/print_pid.c \
	  ./src/start.c \

OBJ = $(SRC:.c=.o)

LIB = -L ./lib/ -lmy

CFLAGS = -I ./include/

NAME = navy

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/my/
	gcc -g3 $(OBJ) -o $(NAME) $(CFLAGS) $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/my/
	rm -f lib/libmy.a

re: fclean all

debug:	CFLAGS += -g3
debug:	re
