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

SRCS_PATH = srcs/

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

OBJS_PATH = objs/

OBJS = $(SRCS:.c=.o)

OBJS_NAME = $(addprefix $(OBJS_PATH), $(OBJS))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir objs 2> /dev/null || echo "" > /dev/null
	@gcc -c $(FLAGS) $< -I $(INC) -o $@

$(NAME): $(OBJS_NAME)
	@make -C libft/
	@make clean -C libft/ 
	gcc -o $@ -I $(SRCS_PATH)$(INC) $(OBJS_NAME) libft/libft.a 

clean:
	@/bin/rm -rf objs

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all
