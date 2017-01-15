# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/09 17:55:16 by rcolleau          #+#    #+#              #
#    Updated: 2017/01/14 17:53:14 by cbouvell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS =	main.c \
		open_file.c \
		first_split.c \
		final_split.c\
		chk_tetri.c \
		ft_puttab.c \
		mv_tetra.c \
		swap_tetri.c \
		tetri_on.c \
		tetri_off.c \
		mk_all.c \
		bck_trck.c \
		crea_tab.c \
		cmp_tetri_tab.c \

INC = 	fillit.h \

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)
	@make clean

$(OBJS):
	@gcc -c $(FLAGS) $(SRCS) -I $(INC)

$(NAME): $(OBJS)
	@gcc -o $(NAME) $(OBJS) ../libft/libft.a -I $(INC)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
