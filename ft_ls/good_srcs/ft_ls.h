/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:57:32 by rcolleau          #+#    #+#             */
/*   Updated: 2017/05/05 14:59:50 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LS_H
# define _FT_LS_H

# include "../libft/libft.h"
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <sys/utsname.h>

# define MACOS 0
# define LINUX 0

typedef struct		s_dir
{
	ino_t			ino;
	off_t			off;
	unsigned short	reclen;
	unsigned char	type;
	unsigned char	namlen;
	char			*name;
	int				root;
	struct s_dir	*prev;
	struct s_dir	*next;
}					t_dir;

typedef struct		s_arg
{
	int				l;
	int				upper_r;
	int				lower_r;
	int				upper_a;
	int				lower_a;
	int				t;
	int				upper_g;
	int				upper_u;
	int				lower_u;
	int				upper_f;
}					t_arg;

int					main(int argc, char **argv);

/*
** 		parse_arg.c
*/
char				*get_arg(char **tbl, t_arg *arg);
void				fill_arg(char c, t_arg **arg);

/*
**		get_dir.c
*/
void				get_dir(char **argv, t_arg *opt);

/*
**		print_dir.c
*/
void				print_dir(t_dir *b, t_arg *opt);

/*
**		exit_func.c
*/
void				exit_func(int i, char *str);

/*
**		sort_list.c
*/
void				sort_list(t_dir **list);
void				rev_sort_list(t_dir **list);

/*
**		add_to_list.c
*/
void	add_top_list(t_dir **lst, t_dir *new);
void	add_end_list(t_dir **lst, t_dir *new);

#endif
