# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/09 17:55:16 by rcolleau          #+#    #+#              #
#    Updated: 2017/05/31 11:40:11 by rcolleau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strndup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strnjoin.c \
		ft_strnjoin_free.c \
		ft_strjoin_free.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strrev.c \
		ft_nblen.c \
		ft_intchr.c \
		ft_ptr.c \
		ft_abs.c \
		ft_foreach.c \
		ft_range.c \
		ft_recursive_factorial.c \
		ft_sqrt.c \
		ft_swap.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstadd_end.c \
		ft_tbllen.c \
		ft_tritbllen.c \
		ft_filecmp.c \
		ft_open_file.c \
		ft_lstfind_link.c \
		ft_count_char.c \
		get_next_line.c \
		ft_putnbrendl.c \
		ft_putnbrendl_fd.c \
		ft_puttbl.c \
		ft_intmap.c \
		error_func.c \
		error_func_i.c \
		ft_lstprint.c \
		check_char_pres.c \
		ft_put_two_arg.c \
		ft_char_swap.c \
		ft_sort_tbl.c \
		ft_put_rev_tbl.c \

INC = 	libft.h \
		get_next_line.h \

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJS):
	@gcc $(FLAGS) -c $(SRCS)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
