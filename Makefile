##
## EPITECH PROJECT, 2018
## CPE_matchstick_2017
## File description:
## Makefile
##

CC		=	gcc -g

CFLAGS		=	-I ./inc -Wextra -W -Wall -Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized -Wunused-but-set-variable

RM		=	rm -rf

SRC		=	src/main.c		\
			src/lib.c 		\
			src/lib_two.c 		\
			src/init.c 		\
			src/get_next_line.c 	\
			src/loop.c 		\
			src/display.c 		\
			src/error.c 		\
			src/input.c 		\
			src/ia/delete_stick.c 	\
			src/ia/game_ended.c 	\
			src/ia/ia_loop.c 	\
			src/ia/res.c 		\
			src/calcul.c 		\

OBJS		=	$(SRC:.c=.o)

NAME		=	matchstick

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all