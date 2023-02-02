##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC = my_strcmp.c \
	  str_to_word_array.c \
	  my_putchar.c \
	  my_putstr.c \
	  my_putnbr.c \
	  my_getnbr.c \
	  my_strlen.c \
	  my_atoi.c \

OBJ = $(SRC:.c=.o)

HEADER = my.h

NAME = libmy.a

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp my.h ../../include

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f libmy.a

re: fclean all
