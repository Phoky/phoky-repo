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

NAME = mlx

SRCS_PATH = srcs/

SRCS = 	main.c \
		read_and_fill.c \
		crea_lstval.c \
		new_val.c \
		print_val.c \
		window_crea.c \
		
INC =

OBJS_PATH = objs/

OBJS = $(SRCS:.c=.o)

OBJS_NAME = $(addprefix $(OBJS_PATH), $(OBJS))

FLAGS = -Wall -Wextra -Werror -g

FRAMEWORK = -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir objs 2> /dev/null || echo "" > /dev/null
	@gcc -c $(FLAGS) $< -o $@

$(NAME): $(OBJS_NAME)
	@make re -C libft/
	@make clean -C libft/ 
	@gcc -o $@ $(FLAGS) $(OBJS_NAME) $(FRAMEWORK) libft/libft.a 

clean:
	@/bin/rm -rf objs

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all
