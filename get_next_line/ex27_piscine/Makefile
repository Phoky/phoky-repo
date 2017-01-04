# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 19:21:09 by rcolleau          #+#    #+#              #
#    Updated: 2016/11/05 14:19:32 by rcolleau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRC = main.c \
	  ft_open.c \
	  ft_putchar.c \
	  ft_putstr.c \

INC = header.h \

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(OBJS):
	gcc -c $(SRC)

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
