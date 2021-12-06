# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 10:28:09 by arohmann          #+#    #+#              #
#    Updated: 2021/09/29 18:54:19 by arohmann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Werror -Wextra -framework OpenGL -framework AppKit

LIBS = -Imlx -Lmlx -lmlx -Ilibft -Llibft -lft

SRC = init.c \
main.c \
fractal.c \
draw.c \
color.c \
hooks.c \
sidebar.c 

all:
	$(CC) $(SRC) -O3 $(LIBS) -o fractol

clean:
	rm -f *.o *~

fclean: clean
	rm -f $(NAME)
	
re: fclean all