# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlecart <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 12:55:07 by rlecart           #+#    #+#              #
#    Updated: 2017/03/28 22:22:06 by rlecart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit
FILE		=	main.c \
				fillit.c \
				tetri_rec.c \
				tetri_pos.c \
				place.c \
				pos.c \
				map.c
SRC			=	$(addprefix src/,$(FILE)) libft/libft.a
OBJ			=	$(FILE:.c=.o)
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(FLAGS) -o $(NAME) $(SRC)

%.o: %.c
	$(CC) -c $< $(FLAGS)

clean:
	make -C libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
